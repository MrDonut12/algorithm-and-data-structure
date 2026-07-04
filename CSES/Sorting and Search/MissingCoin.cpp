#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 1103;
ll n, a[N];
void solve() {
    cin >> n ;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll curr = 0;
    for (int i = 1; i <= n; i++) {
        // cout << a[i] <<  " " << curr << " " << a[i] + 1 << " " << a[i] - curr - 1 << endl;

        if (a[i] - curr - 1 > 0) {
            cout << curr + 1 << "\n";
            return;
        }
        curr += a[i];

    }
    cout << curr + 1 << "\n";

}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
