#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e3 + 276;

int solve(){
	ll x, y;
	cin >> y >> x;
	ll p = max(x - 1, y - 1);
	ll base = p*p;
	if (x == y) {
		cout << base + x << "\n";
	}
	else if (y > x) {
		if (y & 1) {
			cout << base + x << "\n";
		} else {
			cout << base + 2*y - x << "\n";
		}
	} else if (x > y){
		if (x & 1) {
			cout << base + 2*x - y << "\n";
		} else {
			cout << base + y << "\n";
		}
	}
	
	return 0;
}

int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	
	
	return 0;
}
