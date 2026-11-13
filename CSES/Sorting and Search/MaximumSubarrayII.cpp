#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define ll long long
#define ld long double
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
#define fi first
#define se second
#define ii pair<ll, ll>
ll a[N], pre[N];

map < ll, bool > flag;
void solve() {
    ll n, ar, br;
    cin >> n >> ar >> br;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    multiset<ll> st;
    ll ans = LLONG_MIN;

    for (int r = ar; r <= n; r++) {
        st.insert(pre[r - ar]);

        if (r > br) {
            st.erase(st.find(pre[r - br - 1]));
        }

        ans = max(ans, pre[r] - *st.begin());
    }

    cout << ans << '\n';
}

signed main() {
    int t = 1;
    // cin >> tt;
    while (t--) {
        solve();
    }
}
