#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, t;
int main(){
	cin >> t;
	while (t--) {
		ll x, y;
		cin >> x >> y;
		if (x == 1) cout << "1\n1\n";
		else if (x == 3) cout << "3\n1 2 3\n";
		else {
			cout << 1 << " " << (n % 2 == 0) ? (x - y - 1) : (x - y - 2)
				<< " " << x - y << " " << x - y + 1 <<  
		}
		
	}
}
