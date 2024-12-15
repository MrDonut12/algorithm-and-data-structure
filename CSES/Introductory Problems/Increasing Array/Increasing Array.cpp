#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6 + 276;
using namespace std;
ll n, a[N], res = 0;
bool check[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			res += a[i - 1] - a[i];
			
			a[i] = a[i - 1];
		}
		
	}
	cout << res;
	return 0;
}
