#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
ll n, m, k, x, ans, a[N];

ll lsearch(ll x, ll l, ll r) {
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] >= x) {
            r = g - 1;
        } else l = g + 1;
    }
    return l;
}

ll usearch(ll x, ll l, ll r) {
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] > x) {
            r = g - 1;
        } else l = g + 1;
    }
    return l;
}

int main() {
    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++){
        for (int j = i + 1; j < n - 1; j++) {
            ll curr = a[i] + a[j] - 1;
            ll upper = usearch(curr, j + 1, n - 1);
            ll lower = lsearch(a[upper - 1] - a[i], j + 1, n - 1);
            if (lower == n) {
                continue;
            }
            // cout << i << " " << j << endl;
            // cout << a[i] << " " << a[j] << " " << lower << " " << upper << endl;
            ans += (upper - lower);
        }
    }
    cout << ans;
}
