#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define fi first
#define se second
#define pb push_back
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 1; i <= n; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define fastIO ios_base::sync_with_stdio(false); \
            cin.tie(0)

#define endl "\n"


const ll N = 2e5 + 1103;
const ll M = 2e5 + 1103;
ll n, k, m, a[N], res[N];
ll b[N], flag[N];

int search(ll target) {
    ll l = 1, r = n;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] <= target) {
            l = g + 1;
        } else r = g - 1;
    }
    return l;
}


int solve() {
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a + 1, a + 1 + n);
    rep(i, m) {
        ll pos = search(b[i]);

    }
    cout << endl;
    rep(i, n) {
        cout << a[i] << " ";
    }
    return 0;
}

signed main() {
    fastIO;
    ll tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
