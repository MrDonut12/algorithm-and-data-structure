#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long

ll n, k;
const ll N = 2e6 + 1103;
ll dp[N], h[N];
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[2] = abs(h[2] - h[1]);
    dp[3] = min(abs(h[3] - h[2]), abs(h[3] - h[1]));
    for (int i = 3; i <= n; i++) {
        dp[i] = LLONG_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j > 0) dp[i] = min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
        }
    }

    cout << dp[n] << endl;
}
