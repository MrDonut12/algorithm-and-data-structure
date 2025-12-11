#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define fi first
#define se second
#define ll long long
#define ii pair <ll , ll>
#define forto(i, a, b) for(ll i  = a; i <= b; i++)
#define fordto(i, a, b) for(ll i  = a; i >= b; i--)
#define all(x) x.begin(), x.end()
#define sz(x) sizeof(x)
#define endl '\n'


const ll N = 2e5 + 1103;
const ll M = 1103;
const ll P = 1e9 + 7;

ll t, a[N];

struct Seg {
    int n;
    vector <ll> tree;
    Seg(int _n) {
        n = _n;
        tree.resize(n * 4, LLONG_MIN);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id] = a[l];
            return ;
        }
        int g = (l + r) >> 1;
        build(id * 2, l, g );
        build(id * 2 + 1, g + 1, r);
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
    }

    void update(int id, int l, int r, int pos, int val) {
        if (l == r){
            tree[id] = val;
            return ;
        }
        int g = (l + r) >> 1;

        if (pos <= g) {
            update(id * 2, l, g, pos, val);
        } else update(id * 2 + 1, g + 1, r, pos, val);
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
    }

    ll query(int id, int l, int r, int u, int v) {
        if (r < u || l > v) return LLONG_MIN;
        if (u <= l && r <= v) {
            return tree[id];
        }
        int g = (l + r) >> 1;
        ll left = query(id * 2, l , g, u, v);
        ll right = query(id * 2 + 1, g + 1 , r, u, v);
        return max(left, right);
    }
};

void solve() {
    int n, q;
    cin >> n;
    Seg seg(n);
    forto(i, 1, n) cin >> a[i];
    seg.build(1, 1, n);
    cin >> q;
    while ( q--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type == 1) {
            seg.update(1, 1, n, x, y);
        } else {
            cout << seg.query(1, 1, n, x, y) << endl;
        }
    }
}

signed main() {
    FAST_IO
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
    int t = 1;
    // cin >> t
    while(t--) {
        solve();
    }
    return 0;
}
