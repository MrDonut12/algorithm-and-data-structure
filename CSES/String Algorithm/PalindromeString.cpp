#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 1103;
const ll base = 31;
const ll P = 1e9 + 7;

namespace brr {
    string s;

    struct Node {
        ll hl, hr;
        ll len;
    };

    Node tree[N * 4];
    ll pw[N];

    Node merge(Node a, Node b) {
        Node newNode;
        newNode.len = a.len + b.len;

        newNode.hl = (a.hl * pw[b.len] + b.hl) % P;
        newNode.hr = (b.hr * pw[a.len] + a.hr) % P;

        return newNode;
    }

    void buildtree(ll id, ll l, ll r) {
        if (l == r) {
            ll c = s[l] - 'a' + 1;
            tree[id] = {c, c, 1};
            return;
        }

        ll g = (l + r) >> 1;

        buildtree(id * 2, l, g);
        buildtree(id * 2 + 1, g + 1, r);

        tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
    }

    void update(int id, int l, int r, int pos, char c) {
        if (l == r) {
            ll nc = c - 'a' + 1;
            tree[id] = {nc, nc, 1};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(id * 2, l, mid, pos, c);
        else
            update(id * 2 + 1, mid + 1, r, pos, c);

        tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
    }

    Node query(int id, int l, int r, int u, int v) {
        if (v < l || r < u)
            return {0, 0, 0};

        if (u <= l && r <= v)
            return tree[id];

        int g = (l + r) >> 1;

        Node nodeA = query(id * 2, l, g, u, v);
        Node nodeB = query(id * 2 + 1, g + 1, r, u, v);

        return merge(nodeA, nodeB);
    }

    void solve() {
        ll n, q;
        cin >> n >> q >> s;

        pw[0] = 1;
        for (int i = 1; i <= n; i++)
            pw[i] = pw[i - 1] * base % P;

        buildtree(1, 0, n - 1);

        while (q--) {
            ll t, a;
            cin >> t >> a;

            if (t == 1) {
                char c;
                cin >> c;
                update(1, 0, n - 1, a - 1, c);
            }
            else {
                ll b;
                cin >> b;

                Node check = query(1, 0, n - 1, a - 1, b - 1);

                cout << (check.hr == check.hl ? "YES\n" : "NO\n");
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    brr::solve();
}
