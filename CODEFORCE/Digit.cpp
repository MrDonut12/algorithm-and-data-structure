#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
	ll n, d;
	vector <ll> res;
	cin >> n >> d;
	if (d == 0) cout << "1 3 5 7 9";
	else {
		if (n >= 3 || d % 3 == 0) res.push_back(3);
		if (d == 5) res.push_back(5);
		if (n >= 3 || (n == 2 && d == 7)) res.push_back(7);
		if (n >= 6) res.push_back(9);
		else {
			ll fac = 1;
			ll i = 2;
			while (i <= n) {
				fac *= i;
				i++;
			}
			if ((fac * d) % 9 == 0) res.push_back(9);
		}
		cout << 1 << " ";
		for (ll it : res) cout << it << " ";
	}
	cout << "\n";
	
}
int main(){
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
}
