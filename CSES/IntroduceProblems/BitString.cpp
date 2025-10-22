#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;

ll d[N];
const ll MOD = 1e9 + 7;
ll solve (ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll ans = solve(a, b/2) % MOD;
	if (b & 1) {
		return ((ans * ans) % MOD * a % MOD)% MOD;
	} else {
		return (ans * ans) % MOD;
	}
}

int main() {
	ll t;
	cin >> t;
	cout << solve(2,t);
}        
