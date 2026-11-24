#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ii pair<ll,ll>

const ll N = 2e5 + 10;
const ll M = 1103;

namespace dijkstra {

    vector <pair<ll, ll>> adj[N];
    ll n, m, answer = -1;
    ll cnt[N], col[N];

    void dijkstra() {
        priority_queue <pair<ll, ii>, vector<pair<ll, ii>>, greater<pair<ll, ii>>> pq;
        pq.push({0, {1, -1}});

        while (!pq.empty()) {
            ll d = pq.top().first;
            ll u = pq.top().second.first;
            ll c = pq.top().second.second;
            pq.pop();

            if (cnt[u] == 2) continue;
            if (cnt[u] == 1 && col[u] == c) continue; //cook luon
            if (cnt[u] == 0) col[u] = c; //update
            cnt[u]++;

            if (u == n) {
                answer = d;
                break;
            }

            for (int i = 0; i < adj[u].size(); i++) {
                ii v = adj[u][i];
                if (v.second == c) continue;
                pq.push({d + 1, {v.first, v.second}});
            }
        }
    }

    void solve() {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            ll x, y, w;
            cin >> x >> y >> w;
            adj[x].push_back({y, w});
        }

        dijkstra();

        cout << answer;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t = 1;
    // cin >> t;

    while (t--) {
        dijkstra:: solve();
    }
}
