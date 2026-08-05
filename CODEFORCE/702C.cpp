#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll t, n, m;
const ll N = 2e5 + 276;
ll a[N], b[N];

ll bsearch(ll x, ll a[], ll size) {
    ll l = 0, r = size - 1;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] < x) l = g + 1;
        else r = g - 1;
    }
    return l;
}

const ll INF = 1e18;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll ans = 0;

    // linear
    for (int i = 0 ; i < n; i++) {
        ll index = bsearch(a[i], b, m);
        ll distance = INF;
        if (index < m)
            distance = min(distance, llabs(a[i] - b[index]));
        if (index > 0)
            distance = min(distance, llabs(a[i] - b[index - 1]));
        ans = max(distance, ans);
    }

    cout << ans << "\n";
}
