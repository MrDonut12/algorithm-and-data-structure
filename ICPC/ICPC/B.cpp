#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N = 1e5 + 276;
ll n, res, tree[N * 4];
ll lst[N], prevd[N], indices[N];
struct dog {
	ll w, iq, price;
};

dog a[N];

void build_tree(ll id, ll l, ll r) {
    if (l == r) {
        tree[id] = a[l].price;
        return;
    }
    ll g = (l + r) / 2;
    build_tree(id * 2, l, g);        
    build_tree(id * 2 + 1, g + 1, r); 
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

ll query(ll id, ll l, ll r, ll u, ll v, ll iqmin) {
    if (u > r || v < l) return 0; 
    if (l == r && a[l].iq >= iqmin) return tree[id];
    else if (l == r && a[l].iq < iqmin) return INT_MIN;
    int g = (l + r) / 2;
    ll left_query = query(id * 2, l, g, u, v, iqmin);
    ll right_query = query(id * 2 + 1, g + 1, r, u, v, iqmin);
    return max(left_query, right_query);
}

ll tknp(ll l, ll r,  ll target) {
	while (l <= r) {
		ll g = (l + r)/2;
		if (target > a[g].iq) r = g - 1;
		else if (target < a[g].iq) l = g + 1;
		else if (target == a[g].iq) return g;
	}
	return l;
}
bool cmp (dog a, dog b) {
	if (a.w == b.w) return (a.iq > b.iq);
	return (a.w > b.w);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w >> a[i].iq >> a[i].price;
	}
	sort(a + 1, a + 1 + n, cmp);
	build_tree(1, 1, n);
	ll res = INT_MIN;
	for (int i = 1; i <= n; i++) {
		res = max(res , a[i].price + query(1, 1, n, 1, i - 1, a[i].iq));
	}
	cout << res;
}
