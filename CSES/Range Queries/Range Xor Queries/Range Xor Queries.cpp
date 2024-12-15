#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N = 2e5 + 276;
ll n, a[N], tree[N * 4];

void build_tree(int id, int l, int r) {
	if (l == r) {
		tree[id] = a[l];
		return ;
	}
	int g = (l + r)/2;
	build_tree(id * 2, l, g);
	build_tree(id * 2 + 1, g + 1, r);
	tree[id] = tree[id*2] ^ tree[id * 2  + 1];
}
ll  query(int id, int l, int r, int u, int v) {
	if (u > r || v < l) {
		return 0;
	}
	if (u <= l && r <= v) return tree[id];
	int g = (l + r)/2;
	ll a = query(id * 2, l, g, u , v);
	ll b = query(id * 2 + 1, g + 1, r, u , v);
	return a^b;
}
ll q;
int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build_tree(1, 1, n);
	while(q--) {
		ll u, v;
		cin >> u >> v;
		cout << query(1, 1, n, u ,v) << endl;
	}
}
