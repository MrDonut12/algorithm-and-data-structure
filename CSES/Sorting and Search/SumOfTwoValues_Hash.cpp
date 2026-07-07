#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long

const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
const ll INF = 1e9 + 7;
ll n, x, t, a[N];
#define ii pair<ll  ,ll>
unordered_map<ll, ii> pos;
#define fi first
#define se second

void solve() {
    cin >> n >> x;
    unordered_map<int, int> pos;

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (pos.count(x - a[i])) {
            cout << pos[x - a[i]] << " " << i;
            return;
        }
        pos[a[i]] = i;
    }

    cout << "IMPOSSIBLE\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
