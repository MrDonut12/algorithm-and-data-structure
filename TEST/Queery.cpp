#include <bits/stdc++.h>
#define ll int
#define ii pair <ll, ll>
using namespace std;
const ll N = 2e5 + 276;
ll n, m, a[N];
int q;
ii tree[N * 4];
void build_tree(int id, int l, int r) {
	if (l == r) {
		tree[id].first = a[l];
		tree[id].second = a[l];
		return ;
	}
	
	int g = (l + r)/2;
	build_tree(id * 2, l, g);
	build_tree(id * 2 + 1, g + 1, r);
	
	tree[id].first = max(tree[id * 2].first, tree[id * 2 + 1].first);
	tree[id].second = min(tree[id * 2].second , tree[id * 2 + 1].second); 
}

ii query(int id, int l, int r, int u, int v) {
	if (v < l || u > r) {
		return {INT_MIN, INT_MAX};
	}
	 if (u <= l && r <= v) {
        return tree[id];
    }
	int g = (l + r)/2;
	ii a = query(id * 2, l , g, u, v);
	ii b = query(id * 2 + 1, g + 1, r , u , v);
	
	return {max(a.first, b.first), min(a.second, b.second)};
}

int main(){
	freopen("BOBASO.INP", "r", stdin);
	freopen("BOBASO.OUT", "w", stdout);
	cin >> n;
	for (int i = 1;i <= n; i++)  cin >> a[i];
	build_tree(1, 1, n);
	ll res = INT_MIN;
	for (int i = 2; i < n; i++) {
		ll leftq = query(1, 1, n, 1, i - 1).first;
		ll rightq = query(1, 1, n, i + 1, n).second;
		res = max(res, 3*leftq + 2*a[i] - 5*rightq);
	}
	
	return cout << res, 0;
}

