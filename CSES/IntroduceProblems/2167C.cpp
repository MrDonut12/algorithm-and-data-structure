#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        bool ev = false, odd = false;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2 == 0) ev = true;
            else odd = true;
        }
        if (ev && odd) sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << "\n";
    }
}
