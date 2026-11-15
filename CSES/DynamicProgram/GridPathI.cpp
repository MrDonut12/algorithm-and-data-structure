#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll , ll>
#define fi first
#define se second
#define pb push_back
#define endl "\n"

const ll N = 2e6 + 1103;
const ll M = 1103;
const ll P = 1e9 + 7;


// dynamic mindset
// dp[i][j] -> how many ways to reach to (i, j) points
namespace trSolve {
    ll dp[M][M], arr[M][M];
    void solve(ll n) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            for (int j = 1; j <= n; j++) {
                arr[i][j] = s[j - 1];
            }
        }
        if (arr[1][1] == '*') {
            cout << 0 << endl;
            return;
        }
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][j] == '*' || (i == 1 && j == 1)) continue;
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % P;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= n; j++) {
        //         cout << dp[i][j] << " ";
        //     } cout << endl;
        // }
        cout << dp[n][n];
    }

}


signed main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        ll n; cin >> n;
        trSolve:: solve(n);
        // bruteforce:: solve(n);
    }
}
