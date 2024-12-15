#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e6 + 276;
int n, q, sA, sB;

int main() {
 int tt;
	cin >> tt;
	while (tt){
		int n, sa, sb;
		cin >> n >> sa >> sb;
		if (max(sa, sb) < n || abs(sa - sb) < 2) {
			cout << 0 << '\n';
			continue;
		}
		int m = sa + sb;
		int res = 0;
		for (int mask = 0; mask < (1 << m); mask++) {
		if (__builtin_popcount(mask) != sb) {
			continue;
		}
		bool ok = true;
		int cur_a = 0, cur_b = 0;
		for (int i = 0; i + 1 < m; i++) {
			if ((mask >> 1) & 1) {
			cur_a++;
			} else {
				cur_b++;
				if (max(cur_a, cur_b) >= n && abs(cur_a - cur_b) >= 2) {
					ok = false;
					break;
				}
				if (ok) res++;
			}
	cout << res << '\n';
		}
	}
}
}
