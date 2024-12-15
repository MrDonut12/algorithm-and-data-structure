#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ii pair<ll, ll>
#define pb push_back
const ll N = 2e5 + 276;
vector<ii> adj[N];
ll n, m, u, v, s;
const ll INF = 1e9;

void dijkstra(int s, ll d[]) { 
    for (int i = 0; i <= n; i++) d[i] = INF;
    d[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ii top = q.top(); q.pop();
        ll u = top.second;
        ll kc = top.first;
        if (kc > d[u]) continue;
        for (auto it : adj[u]) {
            ll v = it.first;
            ll w = it.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

ll t[N], ss[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll x, y, w;
        cin >> x >> y >> w;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }
    
    cin >> s >> u >> v;
    dijkstra(s, t);
    dijkstra(u, ss);


        cout << t[u] + ss[v] << endl;
  

    return 0;
}

