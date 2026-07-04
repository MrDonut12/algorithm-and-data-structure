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
bool comp(ii a, ii b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}
ii a[N];
map <ll, ll> mp;
void solve() {
    ll n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        mp[x]++; mp[y]--;
    }
    int index = 0, ans = 0;
    for (auto it : mp) {
        index += it.se;
        ans = max(ans, index);
    }
    cout << ans;
}

signed main() {
    int t = 1;
    // cin >> tt;
    while (t--) {
        solve();
    }
}
