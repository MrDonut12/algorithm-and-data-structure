#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 1103;
ll n, ans, a[N], f[N], curr;
unordered_map<ll, ll> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> a[i];
    for (int i = 0 ; i < n ; i++) {
        curr += a[i];
        mp[(curr % n + n) %n]++;
    }
    mp[0]++;
    for (auto it : mp) {
        if (it.second > 1) ans += (it.second - 1)*(it.second)/2;
    }
    cout << ans;
}
