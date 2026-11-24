#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ii pair<ll,ll>

const ll N = 2e5 + 10;

namespace adhoc {
    ll a[N];
    bool present[N];
    long long ans;
    ll n;
    void solve() {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i++) {
            ll spare = 0, m = 0;
            fill(present, present + n + 2, false);
            for (int j = i; j <= n; j++) {
                ll current = a[j];
                if (current == -1) {
                    ++spare;
                } else if (current <= n && !present[current]) {
                    present[current] = true;
                    spare += (current < m);
                }
                while (present[m] || spare > 0) {
                    if (!present[m]) spare--;
                    m++;
                }
                ans += m;
            }
        }

        cout << ans << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    cin >> t;

    while (t--) {
        adhoc::solve();
    }
}
