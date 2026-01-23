#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define rep(i, n) for (int i = 1; i <= n; i++)
#define forto(i, a, b) for (int i = a; i <= b; i++)
#define fordto(i, a, b) for (int i = a; i >= b; i--)
#define endl "\n"
#define debug cout<<"debug:\n";
const ll N = 2e6 + 1103;
const ll M = 1e3 + 1103;
using namespace chrono;

#define fastIO ios_base::sync_with_stdio(false); \
                cin.tie(0);
#define ii pair< ll, ll >

ll a[N*10], b[N*10];
ll n, m, k;



void solve() {
    cin >> n >> m >>  k;
    forto(i, 1, n) cin >> a[i];
    forto(i, 1, m) cin >> b[i];

    ll ans = 0, i = 1, j = 1;
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    while (i <= n && j <= m) {
        ll x = a[i];
        if (b[j] < x - k) {
            j++;
        } else if (b[j] > x + k) {
            i++;
        } else {
            ans++;
            i++;
            j++;
        }
    }
    cout << ans << endl;
}

int main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
