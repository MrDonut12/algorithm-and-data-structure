#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

ll a[N], n, ans = LLONG_MAX;
int main(){
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		ll popon = 0, popoff = 0;
		for (int j = 0; j < n; j++) {
			if (((i >> j) & 1) == 1) popon += a[j];
			else popoff += a[j];

		}
		ans = min(ans, abs(popon - popoff));
	}
	cout << ans;
}
