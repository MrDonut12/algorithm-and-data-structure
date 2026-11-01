#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <ll, ll>

const ll N = 2e5 + 256;
const ll M = 1e3 + 256;

ll q, a[N];

ll get(ll x) {
    ll res = 0;
    while (x) {
        ll t = x % 10;
        x /= 10;
        res += t*t;
    }
    return res;
}

unordered_map <ll, ll> mp;
void solve() {
    mp.clear();
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            a[i] = get(a[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        ++mp[a[i]];
    }

    ll answer = 0;
    for (auto it : mp) {
        if (it.se > 1) {
            answer += (it.se) * (it.se - 1) / 2;
        }
    }

    cout << answer << "\n";
}

int main() {
    q = 1;
    cin >> q;
    while (q--) {
        solve();
    }

}
