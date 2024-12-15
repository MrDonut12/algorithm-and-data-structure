#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N = 21;
ll n, sA, sB;
mt19937 sd(chrono :: steady_clock :: now().time_since_epoch().count());
ll solve() {
    ll dp[N][N] = {0};
    cin >> n >> sA >> sB;
    if (n > max(sA, sB) || abs(sA - sB) < 2) {
        cout << "0\n";
        return 0;        
    }
    
    dp[0][0] = 1; 

    for (int i = 0; i <= 11; i++) {
        for (int j = 0; j <= 11; j++) {
            if (i >= n && j >= n && abs(i - j) < 2) continue;
			else {
            dp[i + 1][j] += dp[i][j];
            dp[i][j + 1] += dp[i][j]; }
        }
    }

    cout << dp[sA][sB] << endl;
    return 0;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        solve();         
    }
    cerr << "Done";
    return 0;
}
