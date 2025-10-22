#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e3 + 276;

ll n, a[N];
int main() {
	cin >> n;
	ll count5 = 0;
	ll temp = 1;
	ll power = 5;
	while (temp) {
		temp = n/power;
		power *= 5;
		count5 += temp;
	}
	cout << count5;
}
