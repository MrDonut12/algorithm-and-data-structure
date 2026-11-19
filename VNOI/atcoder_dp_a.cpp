#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
const ll N = 2e6 + 1103;
ll dp[N], h[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    dp[2] = abs(h[2] - h[1]);
    dp[3] = min(abs(h[3] - h[2]), abs(h[3] - h[1]));
    for (int i = 3; i <= n; i++) {
        dp[i] = min(abs(h[i] - h[i - 1]) + dp[i - 1], abs(h[i] - h[i - 2]) + dp[i - 2]);
    }

    cout << dp[n] << endl;
}
