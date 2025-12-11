#include <bits/stdc++.h>
using namespace std;

#define fastIO ios_base::sync_with_stdio(false); cin.tie(0)
#define forto (i, a, b) for(int i = (a); i <= (b); i++)
#define fordto (i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, n) for (int i = 1; i <= (n); i++)

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define endl "\n"
using ll = long long;
using ld = long double;
using ii = pair <ll , ll>;


const ll N = 2e5 + 256;
const ll M = 1e3 + 256;
const ll P = 1e9 + 7;

ll dp[N];

ll gen_dp(ll n = 1) {
    dp[1] = 9;
    dp[2] = 189;
    int i = 3;
    while (dp[i - 1] <= (ll) 1e18) {
		ll x = 9;
        for (int j = 1; j < i; j++) x *= 10;
        dp[i] = x *  (i) + dp[i - 1];
        i++;
    }
    return i - 1;
}

int query (ll k, ll n) {
	ll index = n - dp[k - 1];      
    index--;                      
    ll stt = index / k;           
    ll num10 = 1;
    for (int i = 1; i < k; i++) num10 *= 10;
    ll num_idx = num10 + stt;     
    string s = to_string(num_idx);
    int pos = index % k;      
    return s[pos] - '0';
}

signed solve(ll m) {
    ll n;
    cin >> n;
    if (n <= dp[1]) cout << n << endl;
    else {
    	for (int i = 2; i <= m; i++) {
    		if (dp[i - 1] < n && n <= dp[i]) {
//    			cout << i << endl;
				ll res = query(i, n);
    			return cout << res << endl, 0;
			}
		}
	}
    return 0;
}

signed main() {
    fastIO;
	int tt = 1, ttt = gen_dp();
    cin >> tt;
    while (tt--) {
        solve(ttt);
    }

    return 0;
}
