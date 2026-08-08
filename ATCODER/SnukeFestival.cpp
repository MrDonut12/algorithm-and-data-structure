#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
const ll N = 2e5 + 1103;
ll n, ans;
ll a[N], b[N], c[N];

int usearch (ll x, ll a[]) {
    ll l = 1, r = n;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] <= x) l = g + 1;
        else r = g - 1;
    }
    return l;
}

int lsearch (ll x, ll a[]) {
    ll l = 1, r = n;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g] < x) l = g + 1;
        else r = g - 1;
    }
    return l;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }

    for (int i = 1 ; i <= n ; i++) {
        cin >> b[i];
    }

    for (int i = 1 ; i <= n ; i++) {
        cin >> c[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    sort(c + 1, c + 1 + n);
    for (int i = 1; i <= n; i++) {
        ll lower = lsearch(b[i], a) - 1;
        ll upper = usearch(b[i], c);
        ans = ans + (lower * (n - upper + 1));
    }
    cout << ans << "\n";

}
