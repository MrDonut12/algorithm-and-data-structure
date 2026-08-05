#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 1103;
ll n, ans, a[N], f[N], curr, t;
unordered_map<ll, ll> mp;

bool ok(ll size) {
    for (int i = 1; i <= n - size + 1; i++) {
        if (f[i + size - 1] - f[i - 1] <= t) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        f[i] = a[i] + f[i - 1]; //prefix
    }

    ll l = 1, r = n;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (ok(g)) {
            ans = g;
            l = g + 1;
        }
        else {
            r = g - 1;
        }
    }
    cout << ans << "\n";

}
