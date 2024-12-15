#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e9 + 7;
const ll N = 1e3 + 276;
ll powUltra(ll x, ll y) {
	if (y == 0) return 1;
	ll half = powUltra(x, y/2)%INF;
	if (y % 2 == 0) {
		return (half*half)%INF;
	} else {
		return (half*x)%INF;
	}
}
ll n, a[N][N], dp[N][N];;

int main(){
	cin >> n;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			a[i][j] = INT_MAX;
			dp[i][j] = INT_MAX;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i ==1 && j == 1) dp[i][j] = a[i][j];
			else dp[i][j] = a[i][j] + min(dp[i - 1][j] , dp[i][j - 1]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		} cout << endl;
	}
}
