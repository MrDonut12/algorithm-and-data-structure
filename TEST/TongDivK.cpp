#include "bits/stdc++.h"
#define ll long long
#define ii pair<ll, ll>
#define endl "\n"
using namespace std;
const ll N = 8e4 + 276;
ll n, a[N], k , prefix[N], res = 0;
int solve(){
	map <ll, ll> cnt;
	res = 0;
	cin >> k >> n;
	for (int i =0; i < n; i++) {
		cin >> a[i];
		prefix[i] = (i != 0) ? (prefix[i - 1] + a[i]): a[i];
	}
	for (int i = 0; i < n; i++) {
		ll d = prefix[i] % k;
		cnt[d]++;
	}
	for (auto it : cnt) {
		if (it.second > 1) res += (it.second) * (it.second - 1) / 2;
	}
	if (prefix[n - 1] % k == 0) res++;
	return cout << res << endl, 0;
}

int main() {
	ll q; cin >> q;
	while (q--) {
		solve();
	}
	return 0;
}
