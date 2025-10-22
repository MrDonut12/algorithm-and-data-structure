#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6 + 276;
using namespace std;
ll n, a[N], res = 0;
bool check[N];
int main() {
	cin >> n; ll k = 0;	if (n == 1) return cout <<"1", 0;
	if (n <= 3) return cout << "NO SOLUTION", 0;
	if (n == 4) return cout <<"2 4 1 3", 0;

	for (int i = 1; i <= n; i+=2) {
		a[i] = ++k;
	}
	for (int i = 2; i <= n; i+=2) {
		a[i] = ++k;
	}
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	return 0;
}
