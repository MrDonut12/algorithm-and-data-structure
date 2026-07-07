#include <bits/stdc++.h>
#include <set>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define ii pair<ll, ll>
#define pb push_back
#define endl "\n"

const ll N = 2e5 + 1103;
const ll M = 1103;
ll n, ans = 0, x;

void solve() {
    cin >> x >> n;
    ans = 0;
    multiset <ll> distance;
    set <ll> node;
    node.insert(0);
    node.insert(x);

    distance.insert(x);
    for (int i = 1; i <= n; i++) {
        ll p; cin >> p;
        set <ll>::iterator it = node.upper_bound(p);
        ll dis1 = *it - p;
        ll num1 = *it;

        ll dis2 = p - *(--it);
        ll num2 = *it;

        node.insert(p);
        distance.insert(dis1);
        distance.insert(dis2);


        it = distance.find(num1 - num2);
        distance.erase(it);
        // ans = max(ans, max(*it - p, p - *(--it)));
        // cout << ans;
        cout << *(--distance.end()) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
