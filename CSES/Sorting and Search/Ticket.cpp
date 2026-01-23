#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define ci pair <char, ll>
#define endl "\n"
#define deb cout<<"debug\n"
#define fi first
#define se second
#define pb push_back
#define forto(i, a, b) for(int i = a; i <= b; i++)
#define fordto(i, a, b) for(int i = a; i >= b; i--)
#define rep(i, n) for(int i = 1; i <= n; i++)
#define fastIO ios_base::sync_with_stdio(false);\
                    cin.tie(0);

using namespace chrono;
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
const ll INF = 1e9 + 7;

ll a[N], b[N];
multiset <ll> s;

void solve() {
    s.clear();

    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    rep(i, n) s.insert(a[i]);
    rep(i, m) {
        multiset <ll> :: iterator it = s.upper_bound(b[i]);
        if (it == s.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            s.erase(it);
        }
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
