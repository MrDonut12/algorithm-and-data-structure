#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair <ll, ll>
const ll N = 2e5 + 1103;
const ll M = 1103;

ll n, k;
ii a[N];
multiset <ll> f;

bool cmp (ii a, ii b) {
    if (a.fi == b.fi) return a.se < b.se;
    return a.fi < b.fi;
}
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a, a + n, cmp);

    ll answer = 0;
    for (int i = 0 ; i < n; i++) {
        auto it = f.upper_bound(a[i].fi);
        if (f.empty() || it == f.end()) {
            answer++;
        } else {
            --it;
            f.erase(it);
        }
        f.insert(a[i].se);
    }
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
