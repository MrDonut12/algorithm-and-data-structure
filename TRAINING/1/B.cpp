#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a == 1) {
        if ((n - 1) % b == 0) cout << "Yes\n";
        else cout << "No\n";
        return;
    }

    ll cur = 1;
    while (cur <= n) {
        if ((n - cur) % b == 0) {
            cout << "Yes\n";
            return;
        }
        if (cur > n / a) break; // chống overflow
        cur *= a;
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) solve();
}
