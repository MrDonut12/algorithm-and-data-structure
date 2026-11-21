#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>

const ll N = 2e5 + 1103;
const ll M = 1103;

namespace solve {

    ll x, y, m;
    string s;

    void solve() {
        cin >> x >> y >> m >> s;
        ll c1 = x, c2 = y, ans = x + y;

        for (int i = 0; i < m; i++) {
            if (s[i] == '+') {
                if (c2 > 0) c2++;
                else { c1--; c2++; }
            } else {
                if (c2 >= 2 || (c2 == 1 && c1 == 0)) {
                    c2--; c1++;
                } else if (c2 == 1) {
                    c1--;
                } else {
                    c1--;
                }
            }
            if (c1 + c2 == 0) break;
            ans = max(ans, c1 + c2);
        }
        cout << ans << "\n";
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
