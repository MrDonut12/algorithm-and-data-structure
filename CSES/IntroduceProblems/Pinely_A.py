from sys import stdin, stdout

data = stdin.buffer.read().strip().split()
it = iter(data)
ni = lambda: int(next(it))
na = lambda n: [int(next(it)) for _ in range(n)]
ns = lambda: next(it).decode()
out = bytearray()
ws = lambda s: out.extend(str(s).encode())
wl = lambda s: ws(str(s) + "\n")

t = ni()
for _ in range(t):
    r, x, d, n = na(4)
    s = ns()
    total = 0
    for i in range(n):
        if s[i] == "2" and r >= x:
            continue
        r = max(0, r - d)
        total += 1
    wl(total)

stdout.buffer.write(out)
