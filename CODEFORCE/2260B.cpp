#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 64;

ll x, y, k;

const ll INF = 1e18 + 7;

void brute() {
    cin >> x >> y >> k;
    for (int i = 0; i<= k ;i++) {
        cout << x << " " << y << " " << y%x << endl;
        x++,y++;
    }


}

void solve() {
    cin >> x >> y >> k;

    const ll digiao = 100;
    ll equals = 1;
    ll step = 0, ans = 0;
    while (equals != digiao && step < k) {
        step++;
        if (x > 1 && y % x == (y - 1) % (x - 1)) {
            equals++;
        } else {
            equals = 1;
        }
        // cout << x << " " << y << " " << y%x << " " << step << endl;
        ans += (y % x);
        x++, y++;
    }

    // cout << step << endl;
    if (step <= k) {
        ans += (k - step) * (y % x);
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);cout.tie(nullptr);
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
}
