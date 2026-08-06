#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
const ll N = 2e5 + 1103;
ll n, ans;
ll a[N];
ll b[32];

int bsearch(int x) {
    ll l = 0, r = n - 1;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] == x) return g;
        else if (a[g] < x) {
            l = g + 1;
        } else r = g - 1;
    }
    return -1;
}

unordered_map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0 ; i < n; i++) cin >> a[i], mp[a[i]]++;
    sort (a, a + n);
    b[0] = 1;
    for (int i = 1 ; i < 32; i++) b[i] = b[i - 1] * 2;
    for (int i = 0 ; i < n ; i++) {
        bool ok = false;
        for (int in = 0 ; in < 32; in++) {
            ll index = bsearch(b[in] - a[i]);
            if ((a[i] == a[index] && mp[a[i]] > 1)) {
                ok = true;
                break;
            } else if ((a[i] != a[index] && index != -1)){
                ok = true;
                break;
            }


        }
        if (!ok) {
            ans++;
        }
    }
    cout << ans << "\n";
}
