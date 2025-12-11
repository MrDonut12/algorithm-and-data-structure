#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    vector<ll> c(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll tc = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        tc += c[i];
    }

    if (n == 0) {
        return ;
    }

    vector<ll> dp(n);
    ll mp = 0;

    for (int i = 0; i < n; ++i) {
         ll mpp = 0;


        for (int j = 0; j < i; ++j) {
            if (a[j] <= a[i]) {
                mpp = max(mpp, dp[j]);
            }
        }

        dp[i] = c[i] + mpp;
        mp = max(mp, dp[i]);
    }

    cout << tc - mp << "\n";
}

int t;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

