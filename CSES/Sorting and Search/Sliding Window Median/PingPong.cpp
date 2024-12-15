#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N = 21;
int n, q, sA, sB;



ll solve(){
	ll dp[N][N];
	for (int i = 0 ; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			dp[i][j] = 0;
		}
	}
	cin >> n >> sA >> sB;
	if (n > max(sA, sB) || abs(sA - sB) > 2) {
		cout << "0\n";
		return 0;		
	}
	
	dp[0][0] = 1;
	for (int i = 0 ; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (i >= n && j >= n && abs(i - j) < 2) continue;
			else {
				dp[i + 1][j] += dp[i][j];
				dp[i][j + 1] += dp[i][j];
			}
		}
	}
	cout << dp[sA][sB] << endl;
}

int main() {
    cin >> q;
    while (q--) {
    	solve();	 	
	}
	cerr << "Done";
    return 0;
}
