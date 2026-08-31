#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

ll n, a[N];
map<ll, ll> cnt;

ll f(ll x) {
    return (x * (x - 1)) >> 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll l = 0;
    ll answer = 0;

    for (ll r = 0; r < n; r++) {
        ++cnt[a[r]];

        while (cnt[a[r]] > 1) {
            --cnt[a[l]];
            ++l;
        }

        ll len = r - l + 1;

        answer += f(len) - f(len - 1);
    }

    cout << answer + n << '\n';
}
