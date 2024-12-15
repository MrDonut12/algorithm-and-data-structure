#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define endl "\n"
ll n, x, k, q;

int main() {
	cin >> q;
	while (q--) {
		cin >> n>> k;
		if (k == 1 && n == 1) cout << "1\n1";
		else if (k == 1 || k == n) cout << -1;
		else if ((k - 1) % 2 == 0) {
			cout << 5 << endl;
			cout << "1 2 " << k << " " << k + 1 << " " << k + 2;
		} else {
			cout << 3 << endl;
			cout << 1 << " " << k << " " << k + 1;
		}
		cout << endl;
	}
}
