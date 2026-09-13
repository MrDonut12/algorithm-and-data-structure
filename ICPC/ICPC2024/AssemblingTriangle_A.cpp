#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 3e5 + 1103;
const ll M = 1103;

ll f[N], a[N];

ll comp(ll k, ll n) {
    if (k == 1) return n;
    if (k == 2) return n * (n - 1) / 2;
    if (k == 3) return n * (n - 1) * (n - 2) / 6;
    return 0;
}

void solve() {
    map <ll, ll> mp;

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }

    ll ans = 0, pre = 0;

    for (auto it : mp) {

        if (it.second >= 3) ans += (comp(3, it.second));


        // a and b
        if (it.second >= 2 && pre >= 1) {
            ans += comp(2, it.second) * comp(1, pre);
        }

        pre += it.second;

    }

    cout << ans << "\n";
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}
