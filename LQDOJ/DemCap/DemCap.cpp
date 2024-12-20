#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll N = 2e6 + 276;

void solve() {
    ll n, a[N], k;
    map< ll, ll> mp;
    cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll res = 0;
    for (pair <ll ,ll > it : mp) {
        
        ll fx = it.first;
        ll fy = k - it.first;
        ll nx = it.second;
        ll ny = mp[fy];
        if (fx == fy) {
            res += nx * (nx - 1) / 2;
        } else if (fx > fy) {
            res += nx * ny;
        }
    }
    cout << res;
}
int main() {
    FAST_IO;
    solve();
    return 0;
}
