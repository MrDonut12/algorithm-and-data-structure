#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 276;
unordered_map <ll ,ll> mpS;
unordered_map <ll ,ll> mpT;
ll n, k, t;

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		mpS[x]++;
	}
	
	for (int i = 1; i <= n; i++) {
		ll x; cin >> x;
		mpT[x]++;
	}
	
	
	return ;
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
