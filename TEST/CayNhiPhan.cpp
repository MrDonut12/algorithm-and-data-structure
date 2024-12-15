#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define ii pair <ll, ll>
const ll N = 2e5 + 276;
ll n, m, a[N], tree[N*4], lazy[N*4], q;

void push(int id) {
	if (lazy[id]) {
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		tree[id * 2] += lazy[id];
		tree[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}

void build_tree(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		lazy[id] = a[l];
		return;
	}
	int g = (l + r) / 2;
	build_tree(id * 2, l, g);
	build_tree(id * 2 + 1, g + 1, r);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll query(int id, int l, int r, int u, int v) {
	if (u > r || v < l) return 0; // Out of range
	if (u <= l && r <= v && id != 1) {
		return tree[id];
	}
	push(id); 
	int g = (l + r) / 2;
	ll a = query(id * 2, l, g, u, v);
	ll b = query(id * 2 + 1, g + 1, r, u, v);
	return a + b;
}

void update(int id, int l, int r, int u, int v, int val) {
	if (u > r || v < l) return; // Out of range
	if (u <= l && r <= v  && id != 1) {
		lazy[id] += val;
		tree[id] += val;
		return;
	}
	push(id); 
	int g = (l + r) / 2;
	update(id * 2, l, g, u, v, val);
	update(id * 2 + 1, g + 1, r, u, v, val);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	build_tree(1, 1, n);
	while (q--) {
		ll t, u, v, val;
		cin >> t;
		if (t == 1) {
			cin >> u >> v >> val;
			update(1, 1, n, u, v, val);
		} else {
			cin >> u >> v;
			cout << query(1, 1, n, u, v) << "\n";
		}
		cout << endl;
		for (int i = 1; i <= n* 4; i++) {
			cout << tree[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

