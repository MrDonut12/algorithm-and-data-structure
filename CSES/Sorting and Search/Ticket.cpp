#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define fi first
#define se second
#define pb push_back
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define fastIO ios_base::sync_with_stdio(false); \
            cin.tie(0)

#define endl "\n"


const ll N = 2e5 + 1103;
const ll M = 2e5 + 1103;
ll n, k, m;
vector <ll> a;
vector <ll> b;
multiset <ll> s;

int solve() {
    s.clear();
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    vector <ll> ans(b.size());
    rep(i, n) {
        s.insert(a[i]);
    }
    rep(i, m) {
        multiset <ll> :: iterator it = s.upper_bound(b[i]);
        if (it == s.begin()) {
            ans[i] = -1;
        } else {
            --it;
            ans[i] = *it;
            s.erase(it);
        }
    }
    rep(i, m) {
        cout << ans[i] << " ";
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
