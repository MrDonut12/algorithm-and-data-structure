#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define ci pair <char, ll>
#define endl "\n"
#define deb cout<<"debug\n"
#define fi first
#define se second
#define pb push_back
#define forto(i, a, b) for(int i = a; i <= b; i++)
#define fordto(i, a, b) for(int i = a; i >= b; i--)
#define rep(i, n) for(int i = 1; i <= n; i++)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0);

using namespace chrono;
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
const ll INF = 1e9 + 7;

ll arr[N];
void solve() {
    int n, x;
    cin >> n >> x;
    forto(i, 1, n) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    ll l = 1, r = n, ans = 0;
    while (l <= r) {
        if (arr[l] + arr[r] <= x) {
            l++;
            r--;
            ans++;
        } else {
            r--;
            ans++;
        }
    }
    cout << ans << endl;
}

signed main() {
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
