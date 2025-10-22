#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
ll n;
int main() {
	cin >> n;
	while(n != 1) {
		cout << n << " ";
		if (n % 2 == 0) n/=2;
		else n = n*3 + 1;
	}
	cout << 1;
	return 0;
}
