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
const ll N = 2e6 + 1103;
const ll M = 1e3 + 1103;
using namespace chrono;

#define fastIO ios_base::sync_with_stdio(false); \
                cin.tie(0);
#define ii pair< ll, ll >

ii arr[N*10];
ll n;
vector <ll> dir[N];

bool cmp(ii a, ii b) {
    return a.se < b.se;
}


void solve() {
    cin >> n;
    rep(i, n) cin >> arr[i].fi >> arr[i].se;
    sort(arr + 1, arr + 1 + n, cmp);
    ll ans = 0, x = 0;
    cout << "deg\n";
    forto(i, 1, n) {
        if (arr[i].fi >= x) {

            cout << arr[i].fi << " " << arr[i].se << endl;
            x = arr[i].se;
                ans++;
        }
    }
    cout << "deg" << endl;
    rep(i, n) {
        cout << arr[i].fi << " " << arr[i].se << endl;
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
