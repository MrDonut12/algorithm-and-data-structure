#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e6 + 1103;
const ll INF = 1e9 + 7;

ll n, a[N], x, d;
ll dp[N];
bool cmp (ll a, ll b) {return a > b;}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= x; i++) dp[i] = INF;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int w = a[i]; w <= x; w++) {
            dp[w] = min(dp[w], dp[w - a[i]] + 1);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}
