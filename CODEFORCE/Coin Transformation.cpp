#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
	ll n;
	cin >> n;
	ll res = 1, c = 0;
	while (n) {
		c++;
		n/=4;
	}
	cout << (1<<c)/2 << "\n";
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
