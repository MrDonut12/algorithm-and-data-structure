#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;

void solve() {
    ll n, x1, x2;
    cin >> n >> x1 >> x2;
    if (n == 1) {cout << x1 << endl; return; }
    cout << min(x1 * ((n % 2 != 0)) + x2 * (n/2), x1 * n) << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
