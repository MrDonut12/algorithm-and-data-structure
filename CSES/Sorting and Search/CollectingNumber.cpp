#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define fi first
#define se second
#define pb insert
#define forto(i, a, b) for(int i = a; i <= b; i++)
#define fordto(i, a, b) for(int i = a; i >= b; i--)
#define rep(i, n) for(int i = 1; i <= n; i++)
#define fastIO ios_base::sync_with_stdio(false);\
                    cin.tie(0);

using namespace chrono;
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;

ll a[N], dp[N];
void solve() {
    int n, m;
    cin >> n>> m;
    forto(i, 1 ,n) cin >> a[i], dp[a[i]] = i;
    int ans = 1;
    forto(i, 2, n) {
        if (dp[i] < dp[i - 1]) ans++;
    }

    forto(i, 1, m) {
        int x, y;
        cin >> x >> y;
        int u = a[x];
        int v = a[y];

        set<int> vv;
        vv.pb(u);
        vv.pb(u + 1);
        vv.pb(v);
        vv.pb(v + 1);

        for (int it : vv) {
            if (it >= 2 && it <= n) {
                if (dp[it] < dp[it - 1])
                    ans--;
            }
        }
        swap(dp[u], dp[v]);
        swap(a[x], a[y]);


        for (int it : vv) {
            if (it >= 2 && it <= n) {
                if (dp[it] < dp[it - 1])
                    ans++;
            }
        }

        cout << ans << '\n';
    }
}


signed main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
