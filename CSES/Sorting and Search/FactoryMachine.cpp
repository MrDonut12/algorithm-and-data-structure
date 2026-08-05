#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;

ll n, m, t, a[N];

bool ok(ll time, ll required) {

    ll total = 0;
    for (int i = 0 ; i < n; i++) {
        total += time/a[i];
        if (total >= required) return true;
    }
    return false;
}

int main() {
    cin >> n >> t;
    // t - required
    ll l = 0, r = 0, ans;
    for (int i = 0 ; i < n; i++) cin >> a[i], r = max(r,  a[i] * t);
    while (l <= r) {
       ll g = (l + r) >> 1;

       if (ok(g, t)) {
           ans = g;
           r = g - 1;
       } else {
           l = g + 1;
       }
   }

   cout << ans;
}
