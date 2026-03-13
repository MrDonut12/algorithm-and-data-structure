#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define ll long long
#define ld long double
#define fi first
#define se second
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define rep(i, n) for (int i = 1; i <= n; i++)
#define ii pair <ll, ll>
#define ci pair <char, ll>
#define pb push_back
#define fastIO ios_base::sync_with_stdio(false); \
                    cin.tie(0);


const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
ll n, k, a[N], ans;
const ll INF = 1e9 + 7;
unordered_map <ll, ll> mp;
void solve() {
    cin >> n;
    forto(i, 1, n) cin >> k, mp[k % 23]++;
    for (auto &it : mp) {
        ans += (it.se - 1) * it.se/2;
    }
    cout << ans;
}
signed main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
