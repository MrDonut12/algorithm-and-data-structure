#include <bits/stdc++.h>
using namespace std;

#define ll int
#define ii pair <ll , ll>
#define fi first
#define se second
#define pb push_back
#define endl "\n"

const ll N = 2e6 + 1103;
const ll M = 1103;
const ll P = 1e9 + 7;


// dynamic mindset
// dp[i][j] -> i for i books and j for maximum page at i books
namespace trSolve {
    ll dp[M][(int)1e5+10], arr[3][M];
    void solve() {
        ll n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) cin >> arr[1][i];
        for (int i = 1; i <= n; i++) cin >> arr[2][i];


        for (int i = 1; i <= n; i++) {
            ll currCoin = arr[1][i];
            ll currPage = arr[2][i];

            for (int j = 1; j <= x; j++) {
                dp[i][j] = dp[i - 1][j];

                if (currCoin <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - currCoin] + currPage);
                }
                // cout <<  dp[i][j] << " ";
            }
        }
        cout << dp[n][x] << endl;
    }

}


signed main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        trSolve:: solve();
        // bruteforce:: solve(n);
    }
}
