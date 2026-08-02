#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;

ll a[N], b[N];
void solve() {
    ll n;
    cin >> n;

    ll oneA = 0, oneB = 0, x = 0;
    bool same = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        oneA += a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        oneB += b[i];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) same = false;
        if (a[i] == 1 && b[i] == 0) x++;
    }

    if (same) {
        cout << 0 << '\n';
    } else if (oneA == 0 || oneB == n) {
        cout << -1 << '\n';
    } else if (x & 1) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}
