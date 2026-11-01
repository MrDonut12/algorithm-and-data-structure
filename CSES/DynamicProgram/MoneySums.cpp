#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e6 + 1103;
ll a[N], dp[N];
void solve() {
    ll n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = s; j > a[i]; j--) {
            if (dp[j - a[i]]) dp[j] = 1;
        }
        dp[a[i]] = 1;
    }
    ll ans = 0;
    for (int i = 1; i < N; i++) {
        ans += dp[i];
    }
    cout << ans << "\n";
    for (int i = 1; i < N; i++) {
        if (dp[i]) cout << i << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) solve();

    return 0;
}
