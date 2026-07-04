#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll N = 2e5 + 276;
const ll M = 1e3 + 1103;

int a[N];

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0 ; i < n; i++) cin >> a[i]; sort(a, a + n);
    ll l = 0, r = n - 1;
    ll ans = 0;

    while (l <= r) {
        if (l == r) {
            ans++;
            break;
        }
        else if (a[l] + a[r] <= x) {
            l++; r--;
            ans++;
        }
        else if (a[l] + a[r] > x) {
            r--;
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
