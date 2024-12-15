#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
ll n ,  a[N];
stack <pair <ll , ll> > f;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		while (f.size() && f.top().first >= a[i]) {
			f.pop();
		} 
		if (f.size() > 0) cout << f.top().second << " ";
		else cout << 0 << " ";
		
		f.push({a[i], i});
	}
	
}
