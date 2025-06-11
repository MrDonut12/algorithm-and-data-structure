#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int min3(int a, int b, int c) {
    return min(min(a, b), c);
}

void solve() {
    long long x;
    scanf("%lld", &x);

    long long ans = 0;
    long long a1 = 0, a2 = 0, a3 = 0;

    while (min3(a1, a2, a3) < x) {
        if (a1 <= a2 && a1 <= a3) {
            a1 = min(a2, a3) * 2 + 1;
        }
        else if (a2 <= a1 && a2 <= a3) {
            a2 = min(a1, a3) * 2 + 1;
        }
        else {
            a3 = min(a1, a2) * 2 + 1;
        }
        ans++;
    }

    printf("%lld\n", ans);
}

int main() {
    int tests;
    scanf("%d", &tests);
    for (int i = 0; i < tests; i++) {
        solve();
    }
    return 0;
}

