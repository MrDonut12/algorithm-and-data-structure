#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define ii pair<ll, ll>
#define forto(i, a, b) for(ll i = a; i <= b;i ++)
#define fordto(i, a, b) for(ll i = a; i >= b;i --)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0)

const ll N = 2e5 + 256;
const ll M = 2e5 + 256;
const ll P = 1e9 + 7;

void solve() {
    string s; cin >> s;
    map <char, ll> mp;
    vector < pair<char, ll> > v;
    rep(i, s.size()) mp[s[i]]++;
    for (auto &it : mp) v.pb(it);

    ll i = 0, j = 1, k = 0;
    bool printA = true;
    while (k <= 50) {
        k++;
        if (v[i].se != 0 && v[j].se != 0) {
            if (printA) {
                printA = false;
                cout << v[i].fi;
                v[i].se--;
            } else {
                printA = true;
                cout << v[j].fi;
                v[j].se--;
            }
        }

        if (v[i].se == 0) {
            i = j;
            j++;
        }

        if (v[j].se == 0) {
            j++;
        }
    }

}

signed main() {
    fastIO;
    freopen("TEST.INP", "r" , stdin);
    freopen("TEST.OUT", "w" , stdout);
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
}
