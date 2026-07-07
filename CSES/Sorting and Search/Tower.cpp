#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define ii pair<ll, ll>
#define pb push_back
#define endl "\n"

const ll N = 2e5 + 1103;
const ll M = 1103;
vector<ii> a;
ll n, ans = 1;


bool cmp(ii a, ii b) {
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi > b.fi;
}

void solve() {
    cin >> n;
    multiset <ll> tower;
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        multiset <ll>::iterator it = tower.upper_bound(x);
        if (it == tower.end()) {
            tower.insert(x);
        } else {
            tower.erase(it);
            tower.insert(x);
        }
    }
    cout << tower.size() << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
