#include <bits/stdc++.h>
using namespace std;
#define div /
#define ll long long


const ll N = 2e6 + 276;
const ll INF = 1e9 + 7;
const ll base = 31; 

ll n, s, a[N];
ll result = INF;


int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	ll currs = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1, j = 1; i <= n; i++) {
		currs += a[i];
		while (currs - a[j] >= s) {
			currs -= a[j++];
			result = min(result, 1LL*i - j + 1);
		}
//		cout << i << " " << j << " " << i - j + 1 << "  " << currs << endl;
	}
	if (result > n) cout << "-1";
	else cout << result;
	return 0;
	
}
