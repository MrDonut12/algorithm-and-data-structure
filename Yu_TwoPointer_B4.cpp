#include <bits/stdc++.h>
using namespace std;
#define div /
#define ll long long

const ll N = 2e6 + 256;
const ll INF = 1e9 + 7;
const ll base = 31;

ll n, a[N], s;
ll result;

int main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s; 
	for (int i = 1; i <= n; ++i) cin >> a[i];
	ll currs = 0;
	for (int i = 1, j = 1; i <= n; ++i) {
		currs += a[i];
		while (currs >= s) {
			currs -= a[j++];
			result += (n - i + 1);
			
		}
	}
	
	cout << result;
	return 0;
}
