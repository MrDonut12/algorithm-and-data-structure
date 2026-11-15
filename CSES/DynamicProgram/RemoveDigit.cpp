#include <bits/stdc++.h>
#include <climits>
#include <sched.h>
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


//greedy - AC =)))
namespace greedy {
    ll dp[N];
    void solve(ll n) {
        ll step = 0;
        while (n) {
            ll tmp = n;
            ll maxd = LLONG_MIN;
            while (tmp) {
                maxd = max(tmp % 10, maxd);
                tmp /= 10;
            }
            step++;
            n -= maxd;
        }
        cout << step << endl;
    }
}

// dynamic mindset
namespace trSolve {
    ll dp[N];
    void solve(ll n) {
        memset(dp, 0x3f, sizeof(dp));
        dp[n] = 0;
        for (int i = n; i >= 0; i--) {
            ll tmp = i;
            while (tmp) {
                ll c = tmp % 10;
                tmp /= 10;
                dp[i - c] = min(dp[i - c], dp[i] + 1);
            }
        }
        cout << dp[0] << endl;
    // for (int i = 0; i <= n; i++) cout << dp[i] << " ";
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
