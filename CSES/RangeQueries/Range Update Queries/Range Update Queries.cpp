#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll INF = 1e15;
const ll N = 2e5 + 276;
ll n, t[N * 4], lazy[N * 4];

void push(int id) {
	if (lazy[id]) {
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		t[id * 2] += lazy[id];
		t[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}

ll get(int id, int l, int r, int u, int v) {
	if (u > r || v < l) return INF;
	if (l == r) return t[id];
	int g = (l + r) / 2;
	push(id);
	ll a = get(id * 2, l, g, u, v);
	ll b = get(id * 2 + 1, g + 1, r, u, v);
	return min(a, b);
}

void update(int id, int l, int r, int u, int v, int x) {
	if (u > r || v < l) return;
	if (u <= l && r <= v) {
		lazy[id] += x;
		t[id] += x;
		return;
	}
	push(id);
	int g = (l + r) / 2;
	update(id * 2, l, g, u, v, x);
	update(id * 2 + 1, g + 1, r, u, v, x);
	t[id] = min(t[id * 2], t[id * 2 + 1]);
}

int main() {
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		update(1, 1, n, i, i, x);
	}
	while (q--) {
		ll qu, u, v, val;
		cin >> qu;
		if (qu == 1) {
			cin >> u >> v >> val;
			update(1, 1, n, u, v, val);
		} else {
			cin >> u;
			cout << get(1, 1, n, u, u) << endl;
		}
	}
}

