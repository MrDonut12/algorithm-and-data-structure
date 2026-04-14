#!/usr/bin/env python3
# stress.py - So sánh output của solution.cpp và code.java
# Usage: python3 stress.py [số_test] [--stop-on-fail]
#
# Yêu cầu trước khi chạy:
#   g++ -O2 -o gen gen.cpp
#   g++ -O2 -o solution solution.cpp
#   javac code.java   (nếu chưa có code.class)

import os
import subprocess
import sys
import time

# ── Cấu hình ──────────────────────────────────────────────────
NUM_TESTS = int(sys.argv[1]) if len(sys.argv) > 1 else 100
STOP_ON_FAIL = "--stop-on-fail" in sys.argv
TIME_LIMIT = 5.0  # seconds mỗi lần chạy
SAVE_FAIL_DIR = "failed_tests"
# ──────────────────────────────────────────────────────────────

GREEN = "\033[92m"
RED = "\033[91m"
YELLOW = "\033[93m"
CYAN = "\033[96m"
RESET = "\033[0m"


def run(cmd, input_data, timeout=TIME_LIMIT):
    """Chạy lệnh với stdin, trả về (stdout, stderr, returncode, elapsed)"""
    start = time.time()
    try:
        result = subprocess.run(
            cmd, input=input_data, capture_output=True, text=True, timeout=timeout
        )
        elapsed = time.time() - start
        return result.stdout.strip(), result.stderr.strip(), result.returncode, elapsed
    except subprocess.TimeoutExpired:
        return None, "TLE", -1, timeout


def compile_check():
    ok = True
    if not os.path.exists("gen.exe"):
        print("[ERROR] gen.exe không tồn tại. Hãy chạy: g++ -O2 -o gen gen.cpp")
        ok = False
    if not os.path.exists("solution.exe"):
        print(
            "[ERROR] solution.exe không tồn tại. Hãy chạy: g++ -O2 -o solution solution.cpp"
        )
        ok = False
    if not os.path.exists("code.class"):
        print("[ERROR] code.class không tồn tại. Hãy chạy: javac code.java")
        ok = False
    return ok


def main():
    if not compile_check():
        sys.exit(1)

    os.makedirs(SAVE_FAIL_DIR, exist_ok=True)

    passed = 0
    failed = 0
    tle_count = 0

    print(f"{CYAN}{'=' * 55}")
    print(f"  Stress Test: solution.cpp  vs  code.java")
    print(f"  Số test: {NUM_TESTS} | TL: {TIME_LIMIT}s | Stop on fail: {STOP_ON_FAIL}")
    print(f"{'=' * 55}{RESET}\n")

    for seed in range(1, NUM_TESTS + 1):
        # 1. Sinh test
        test_input, _, rc, _ = run(["gen.exe", str(seed)], "")
        if rc != 0:
            print(f"{RED}[SEED {seed:04d}] Gen failed{RESET}")
            continue

        # 2. Chạy solution.cpp
        out_sol, err_sol, rc_sol, t_sol = run(["solution.exe"], test_input)

        # 3. Chạy code.java
        out_java, err_java, rc_java, t_java = run(["java", "code"], test_input)

        # 4. Xử lý TLE
        if out_sol is None or out_java is None:
            tle_count += 1
            who = "solution" if out_sol is None else "java"
            print(f"{YELLOW}[SEED {seed:04d}] TLE on {who}{RESET}")
            continue

        # 5. So sánh
        if out_sol == out_java:
            passed += 1
            bar = "#" * (seed * 30 // NUM_TESTS)
            print(
                f"{GREEN}[SEED {seed:04d}] OK{RESET}  "
                f"sol={t_sol:.3f}s  java={t_java:.3f}s  "
                f"[{bar:<30}] {seed}/{NUM_TESTS}"
            )
        else:
            failed += 1
            print(f"\n{RED}{'=' * 55}")
            print(f"  [SEED {seed:04d}] WRONG ANSWER!")
            print(f"{'=' * 55}{RESET}")

            # In test input
            lines = test_input.split("\n")
            preview = "\n".join(lines[:6])
            if len(lines) > 6:
                preview += f"\n  ... ({len(lines) - 6} dòng nữa)"
            print(f"{CYAN}--- Input ---{RESET}\n{preview}")
            print(f"{CYAN}--- solution.cpp output ---{RESET}\n{out_sol}")
            print(f"{CYAN}--- code.java output ---{RESET}\n{out_java}")
            print()

            # Lưu test lỗi
            fail_file = os.path.join(SAVE_FAIL_DIR, f"seed_{seed:04d}.txt")
            with open(fail_file, "w") as f:
                f.write(f"=== SEED {seed} ===\n")
                f.write(f"--- INPUT ---\n{test_input}\n")
                f.write(f"--- SOLUTION OUTPUT ---\n{out_sol}\n")
                f.write(f"--- JAVA OUTPUT ---\n{out_java}\n")
            print(f"{YELLOW}  Đã lưu test lỗi vào: {fail_file}{RESET}\n")

            if STOP_ON_FAIL:
                break

    # Tổng kết
    print(f"\n{CYAN}{'=' * 55}")
    print(f"  KẾT QUẢ: {passed} passed | {failed} failed | {tle_count} TLE")
    print(f"{'=' * 55}{RESET}")

    if failed == 0 and tle_count == 0:
        print(f"{GREEN}  ✓ Tất cả test đều đúng!{RESET}")
    elif failed > 0:
        print(
            f"{RED}  ✗ Có {failed} test sai. Kiểm tra thư mục '{SAVE_FAIL_DIR}/'  {RESET}"
        )


if __name__ == "__main__":
    main()
