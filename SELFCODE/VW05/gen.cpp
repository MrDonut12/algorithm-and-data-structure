// gen.cpp - Sinh test ngẫu nhiên
// Usage: ./gen <seed>
#include <bits/stdc++.h>
#include <random>
using namespace std;

int main(int argc, char* argv[]) {
    int seed = (argc > 1) ? atoi(argv[1]) : 42;
    mt19937 rng(seed);

    // Sinh n, m sao cho n*m < 10^6
    // Để đa dạng: đôi khi n hoặc m nhỏ, đôi khi cả hai vừa
    auto randint = [&](int lo, int hi) {
        return uniform_int_distribution<int>(lo, hi)(rng);
    };

    int n, m;
    // Chọn n trước trong [1, 1000], rồi m trong [1, 10^6/n]
    // Đảm bảo n,m >= 3 để có submatrix 3x3 hợp lệ (tuỳ đề)
    n = randint(3, 1000);
    int max_m = min(1000, (int)(1e6 / n));
    if (max_m < 3) max_m = 3; // đảm bảo luôn có ít nhất 1 submatrix 3x3
    m = randint(3, max_m);

    cout << n << " " << m << "\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Giá trị trong [-100, 100] để test cả số âm
            cout << randint(-100, 100);
            if (j < m - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
