#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 1103;
ll n, x, t;
pair <ll, ll> a[N];
#define fi first
#define se second

bool cmp(pair <ll, ll> a,pair <ll, ll>  b) {
    return a.fi < b.fi;
}

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i].fi, a[i].se = i;
    sort(a + 1, a + 1 + n, cmp);

    int i = 1, j = n;
    while (i < j) {
        if (a[i].fi + a[j].fi == x) {
            cout << a[i].se << " " << a[j].se << "\n";
            return ;
        } else if (a[i].fi + a[j].fi > x) {
            j--;
        } else {
            i++;
        }
    }
    cout << "IMPOSSIBLE\n";

}

int main() {
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
