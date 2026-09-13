#include <bits/stdc++.h>
using namespace std;


#define ll long long
const ll N = 2e5 + 1103;
string str[N];
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }

    sort(str + 1, str + 1 + n);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << str[i] << " " << str[j] << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
