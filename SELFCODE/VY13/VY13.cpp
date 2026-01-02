#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define ii pair<ll, ll>
#define forto(i, a, b) for(ll i = a; i <= b;i ++)
#define fordto(i, a, b) for(ll i = a; i >= b;i --)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0)

const ll N = 2e5 + 256;
const ll M = 2e5 + 256;
const ll P = 1e9 + 7;

using namespace chrono;
string arr[N];
int freq[26];
int cur_arr[26];
int cur[26];
int solve() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    cin >> k >> n;
    forto(i, 0, k - 1) {
        cin >> arr[i];
        ++freq[arr[i][0] - 'a'];
    }
    int p = 0;
    sort(arr, arr + k);
    forto(i, 0, 25) {
        if (freq[i]) {
            cur_arr[i] = p;
            p += freq[i];
        }
    }
    forto(i, 1, n) {
        char c; cin >> c;
        int vc = c - 'a';
        int pos = cur_arr[vc] + cur[vc];
        cur[vc] = (cur[vc] + 1) % freq[vc];
        cout << arr[pos] << endl;
    }

}


signed main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
