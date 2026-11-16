#include <bits/stdc++.h>
#include <ios>
using namespace std;
#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
const ll N = 2e6 + 1103;
const ll M = 1103;
const ll P = 1e9 + 7;

namespace solve {
    ll n, m, ans;
    void solve() {
        cin >> n >> m;
        vector <ll> arr(n);
        vector < vector <ll> > dp(n + 1, vector<ll> (m + 1, 0));

        for (auto &v : arr) cin >> v;
        // base state
        if (arr[0] == 0) {
            for (int i = 1; i <= m; i++) {
                dp[1][i] = 1;
            }
        } else {
            dp[1][arr[0]] = 1;
        }

        //dp
        for (int i = 2; i <= n; i++) {
            ll currNumber = arr[i - 1];
            if (currNumber != 0) {
                dp[i][currNumber] = (dp[i][currNumber] + dp[i - 1][currNumber]) % P;
                if (currNumber != 1) dp[i][currNumber] = (dp[i][currNumber] +  dp[i - 1][currNumber - 1]) % P;
                if (currNumber != m) dp[i][currNumber] = (dp[i][currNumber] + dp[i - 1][currNumber + 1]) % P;
                continue;
            }

            for (int j = 1; j <= m; j++) {
                currNumber = j;
                dp[i][currNumber] = (dp[i][currNumber] + dp[i - 1][currNumber]) % P;
                if (currNumber != 1) dp[i][currNumber] = (dp[i][currNumber] +  dp[i - 1][currNumber - 1]) % P;
                if (currNumber != m) dp[i][currNumber] = (dp[i][currNumber] + dp[i - 1][currNumber + 1]) % P;
            }
        }
        for (int i = 1; i <= m; i++) {
            ans = (ans + dp[n][i]) % P;
        }
        cout << ans << endl;
    }

}

signed main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve:: solve();
    }
}
