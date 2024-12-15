#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
const ll INF = 1e9 + 7;
ll n, dp[N];
int main(){
	cin >> n;
	dp[0]= 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if (j <= i) {
				dp[i] = (dp[i] + dp[i - j])%INF;
				cout << i << " " << i - j << endl;
			}
		}
	}

	cout << dp[n];
}
