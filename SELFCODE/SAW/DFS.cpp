#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    ll S, T;
    cin >> m >> S >> T;

    vector<pair<ll,ll>> edges(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    auto canReach = [&](int t) {
        unordered_map<ll, vector<ll>> adj;
        adj.reserve(t * 2);

        for (int i = 1; i <= t; i++) {
            adj[edges[i].first].push_back(edges[i].second);
        }

        unordered_set<ll> vis;
        queue<ll> q;

        q.push(S);
        vis.insert(S);

        while (!q.empty()) {
            ll u = q.front(); q.pop();
            if (u == T) return true;

            if (!adj.count(u)) continue;

            for (ll v : adj[u]) {
                if (!vis.count(v)) {
                    vis.insert(v);
                    q.push(v);
                }
            }
        }
        return false;
    };

    int l = 1, r = m, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (canReach(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}

