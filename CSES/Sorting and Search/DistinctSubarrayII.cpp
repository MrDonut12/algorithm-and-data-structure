#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;

ll n, a[N], k;
map <ll,ll> cnt;

void solve() {
    cin >> n >> k;
    for (int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    ll l = 0, ans = 0;
    for (ll r = 0; r < n; r++) {
        ++cnt[a[r]];

            while (cnt.size() > k) {
                --cnt[a[l]];
                if(cnt[a[l]] == 0) cnt.erase(a[l]);
                l++;
            }

            ans += (r - l + 1);

    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
