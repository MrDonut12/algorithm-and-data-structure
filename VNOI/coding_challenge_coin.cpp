#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ii pair<ll,ll>
#define forto(i,a,b) for(ll i=a;i<=b;i++)
#define fordto(i,a,b) for(ll i=a;i>=b;i--)
#define all(x) x.begin(), x.end()
#define sz(x) sizeof(x)
#define endl '\n'

const int MAXM = 200000 + 5;

int n, m;
pair<int,int> edges[MAXM];
vector<int> adj[MAXM];
vector<int> radj[MAXM];
int indeg_tmp[MAXM];
int used_tmp[MAXM];
int ans_vec[MAXM];

void build_graph_up_to(int t){
    for(int i=0;i<n;i++){ adj[i].clear(); radj[i].clear(); indeg_tmp[i]=0; used_tmp[i]=0; }
    for(int i=0;i<t;i++){
        int u = edges[i].fi;
        int v = edges[i].se;
        adj[u].pb(v);
        radj[v].pb(u);
        indeg_tmp[v]++;
    }
}

void topo_order(vector<int>& topo){
    topo.clear();
    queue<int> q;
    for(int i=0;i<n;i++) if(indeg_tmp[i]==0) q.push(i);
    while(!q.empty()){
        int u=q.front(); q.pop();
        topo.pb(u);
        for(int v: adj[u]){
            indeg_tmp[v]--;
            if(indeg_tmp[v]==0) q.push(v);
        }
    }
}

void compute_reach_counts(int t, vector<int>& coins, vector<int>& leftSet, vector<int>& rightSet){
    build_graph_up_to(t);
    vector<int> topo;
    topo_order(topo);
    int W = (n + 63) >> 6;
    vector< vector<uint64_t> > reach_down(n, vector<uint64_t>(W));
    for(int i=0;i<n;i++){
        int w = i >> 6;
        reach_down[i][w] |= (1ull << (i & 63));
    }
    for(int idx = (int)topo.size()-1; idx>=0; --idx){
        int u = topo[idx];
        for(int v: adj[u]){
            uint64_t *pu = reach_down[u].data();
            uint64_t *pv = reach_down[v].data();
            for(int k=0;k<W;k++) pu[k] |= pv[k];
        }
    }
    vector< vector<uint64_t> > reach_up(n, vector<uint64_t>(W));
    for(int i=0;i<n;i++){
        int w = i >> 6;
        reach_up[i][w] |= (1ull << (i & 63));
    }
    for(int idx = 0; idx < (int)topo.size(); ++idx){
        int u = topo[idx];
        for(int v: radj[u]){
            uint64_t *pu = reach_up[u].data();
            uint64_t *pv = reach_up[v].data();
            for(int k=0;k<W;k++) pu[k] |= pv[k];
        }
    }
    leftSet.clear();
    rightSet.clear();
    for(int x: coins){
        long long desc = 0, anc = 0;
        uint64_t *pd = reach_down[x].data();
        uint64_t *pu = reach_up[x].data();
        for(int k=0;k<W;k++){
            desc += __builtin_popcountll(pd[k]);
            anc += __builtin_popcountll(pu[k]);
        }
        desc -= 1;
        anc -= 1;
        if(desc + anc + 1 == n) rightSet.pb(x);
        else leftSet.pb(x);
    }
}

void solve_range(int l, int r, vector<int>& coins){
    if(coins.empty()) return;
    if(l + 1 == r){
        for(int x: coins){
            if(l == m+1) ans_vec[x] = -1;
            else ans_vec[x] = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    vector<int> leftSet, rightSet;
    compute_reach_counts(mid, coins, leftSet, rightSet);
    solve_range(l, mid, leftSet);
    solve_range(mid, r, rightSet);
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        edges[i] = {a-1, b-1};
    }
    vector<int> allc;
    for(int i=0;i<n;i++) allc.pb(i);
    solve_range(0, m+1, allc);
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << ans_vec[i];
    }
    cout << '\n';
}

signed main(){
    FAST_IO
    freopen("TEST.INP","r",stdin);
    freopen("TEST.OUT","w",stdout);
    int tt=1;
    while(tt--) solve();
    return 0;
}
