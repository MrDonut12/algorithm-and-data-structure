#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e3 + 276;

ll ansche[] = {0, 0, 6, 28, 96, 252, 550, 1056};
int solve(ll n){
	if (n < 8) { cout << ansche[n] << "\n"; return 0; } 
	
	ll ans = 4 * (n * n - 3);
	ans += 8 * (n * n - 4);
	ans += 4 * (n - 4) * (n * n - 5);
	ans += 4 * (n *n - 5);
	ans += 4 * (n - 4) * (n * n - 7);
	ans += ((n - 4) * (n - 4)) * (n * n - 9);
 	cout << ans/2 << "\n";
	
	return 0;
}

int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	ll t;
	cin >> t;
	for (long long i = 1; i <= t; i++) solve(i*1LL);
	
	
	return 0;
}
