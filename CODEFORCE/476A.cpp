#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, l1 = 0, ans = INT_MAX;

int main() {
    cin >> n >> m;
    if (m > n) 
    	return cout << -1, 0;
    	
    ll minS = (n + 1)/2;
    for (int l2 = minS; l2 >= 0; l2--) {
    	l1 = (minS - l2) * 2;
    	if ((l1 + l2) % m == 0)
    		ans = min(l1 + l2, ans);
	}
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}

