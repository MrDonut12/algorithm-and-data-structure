#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 1103;
ll dp[N][N], n, k, answer;

int main(){
    cin >> n >> k;

    dp[0][0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int q = 1; q <= n; q++) {

            if ((mask >> (q - 1)) & 1) {
                continue;
            }

            for (int p = 0; p <= n; p++) {
                if (p != 0 || abs(p - q) > k) {
                    continue;
                }

                ll nmask = mask | (1 << (p - 1));
                dp[nmask][p] += dp[mask][q];
            }

        }
    }
}
