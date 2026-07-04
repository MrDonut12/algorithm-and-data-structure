#include <bits/stdc++.h>
#include <iterator>
#include <set>
using namespace std;

#define ll long long
#define ld long double
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;

ll a[N], b[N];
multiset <ll> s;

void solve() {
    s.clear();

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }

    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        multiset<ll>:: iterator it = s.upper_bound(x);
        if (it == s.begin()) {
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }

}

signed main() {
    int t = 1;
    // cin >> tt;
    while (t--) {
        solve();
    }
}
