#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
ll a[N], b[N], ans, n, bonus, atotal, btotal;

bool check(ll cake) {
    ll bi = 0;

    for (int i = 1; i <= n; i++) {
        ll need = a[i] * cake;

        if (need > b[i]) {
            bi += need - b[i];

            if (bi > bonus)
                return false;
        }
    }

    return true;
}

int main() {
    cin >> n >> bonus;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    ll l = 0, r = 2e9;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (check(g)) {
            l = g + 1;
            ans = g;
        } else {
            r = g - 1;
        }
    }
    cout << ans << "\n";
}
