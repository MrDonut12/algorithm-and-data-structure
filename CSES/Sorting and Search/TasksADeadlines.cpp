#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
const ll N = 2e5 + 1103;
ll n, ans;
ii a[N];

bool cmp(ii a, ii b) {
    if (a.fi == b.fi) return a.se > b.se;
    return a.fi < b.fi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll curr = 0;
    for (int i = 1; i <= n; i++) {
        curr += a[i].fi;
        ans += a[i].se - curr;
    }
    cout << ans << "\n";

}
