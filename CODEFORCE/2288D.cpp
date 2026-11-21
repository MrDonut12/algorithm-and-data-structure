#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>

const ll N = 2e5 + 1103;
const ll M = 1103;

namespace solve {

    ll n, a[N], pre[N], suf[N];

    bool ok(ll X) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] > X || suf[i] > X) sum += a[i];
        }
        return sum <= X;
    }

    void solve() {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];

        pre[0] = 0;
        for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
        suf[n + 1] = 0;
        for (int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

        ll lo = 1, hi = pre[n];
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            if (ok(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        solve:: solve();
    }
}
