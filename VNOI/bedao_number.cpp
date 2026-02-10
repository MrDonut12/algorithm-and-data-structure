#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define ll long long
#define ld long double
#define fi first
#define se second
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define rep(i, n) for (int i = 1; i <= n; i++)
#define ii pair <ll, ll>
#define ci pair <char, ll>
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); \
                    cin.tie(0);


const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
ll n, k, a[N];
const ll INF = 1e9 + 7;

ll powd(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % INF;
    ll ans = powd(a, b / 2) % INF;
    ans = (ans * ans) % INF;
    if (b & 1) ans = (ans * a) % INF;
    return ans;
}




void solve() {
    cin >> n >> k;
    ll index = 0;
    for (i = 1; i <= 100; i++) {
        for (j = 1; j <= i; j++) {
            index++;
            if (index == k) {

            }
        }
    }
}
signed main() {
    fastIO;
    freopen("TEST.INP", "r", "stdin");
    freopen("TEST.OUT", "w", "stdout");
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
