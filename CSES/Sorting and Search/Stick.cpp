#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define rep(i, n) for (int i = 1; i <= n; i++)
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
const ll N = 2e6 + 1103;
const ll M = 1e3 + 1103;
using namespace chrono;

#define fastIO ios_base::sync_with_stdio(false); \
                cin.tie(0);

ll arr[N*10];
map <ll, ll> dp;
ll n;

void solve() {
    cin >> n;
    rep(i, n) cin >> arr[i], dp[arr[i]]++;
        sort(arr + 1, arr + 1 + n);
        ll pos = (n & 1) ? (n / 2 + 1) : (n / 2);

    ll median = arr[pos];
    ll ans= 0;
    rep(i, n) {
        ans += abs(median - arr[i]);
    }
    cout << ans;
}

int main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
