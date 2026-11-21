#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>

const ll N = 2e5 + 1103;
const ll M = 1103;

namespace solve {

    ll x, y, m;
    string s;

    void solve() {
        cin >> x >> y >> m >> s;

        ll cnt = x + y, high = y;
        ll ans = cnt;

        for (char c : s) {
            if (cnt == 0) break;

            if (c == '+') {
                if (high > 0) cnt++;
                high++;
            }
            else {
                if (high > 0) high--;
                else cnt--;
            }

            ans = max(ans, cnt);
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
        solve::solve();
    }
}
