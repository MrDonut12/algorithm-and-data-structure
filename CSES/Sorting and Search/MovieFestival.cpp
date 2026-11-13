#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define ld long double
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
#define fi first
#define se second
#define ii pair<ll, ll>
ii a[N];

bool cmp (ii a, ii b) {
    return a.se < b.se;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    ll index = 0, ans = 0;
    sort(a + 1, a + 1 + n, cmp);

    multiset <ll> endpoints;
    for (int i = 1; i <= k; i++) endpoints.insert(0);
    for (int i = 1; i <= n; i++) {
        multiset <ll> :: iterator it = endpoints.upper_bound(a[i].fi);

        if (it == endpoints.begin()) {
            continue;
        }
        --it;
        endpoints.erase(it);
        ++ans;
        endpoints.insert(a[i].se);
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    // cin >> tt;
    while (t--) {
        solve();
    }
}
