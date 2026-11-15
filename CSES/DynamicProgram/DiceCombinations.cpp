#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
const ll N = 2e6 + 1103;
const ll M = 1103;
const ll INF = 1e9 + 7;
using namespace chrono;
ll dp[N];
void solve() {
    ll n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6; j ++) {
            if (i >= j) dp[i] = (dp[i] + dp[i - j]) % INF;
        }
    }
    cout << dp[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll tst = 1;
    // cin >> tst;
    while (tst--) {
        solve();
    }
}
