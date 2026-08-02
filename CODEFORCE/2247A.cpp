#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;

    int pos = 0;
    int neg = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pos += (x == 1);
        neg += (x == -1);
    }

    cout << (abs(pos - neg) % 4 == 0 ? "YES\n" : "NO\n");

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
}
