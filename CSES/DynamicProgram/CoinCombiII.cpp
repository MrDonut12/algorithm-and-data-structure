#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e6 + 1103;
const ll INF = 1e9 + 7;

ll n, a[N], t, x, d;
ll dp[N];

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        ll coin = a[i];
        for (int j = coin; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coin]) % INF;
        }
    }

    cout << dp[x] << "\n";
}
