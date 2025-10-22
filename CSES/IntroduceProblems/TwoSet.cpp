#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;

ll d[N];

void solve (ll n) {
	ll sum = (n * (n + 1))/2;
	if (sum & 1) {
		cout << "NO";
		return ;
	}
	cout << "YES\n";
	sum /= 2;
	ll cur = n;
	ll index = 0;
	while (sum) {	
		index++;
		if (sum <= cur && !d[sum]) {
			d[sum] = 1;
			sum = 0;
			break;
		} 
		
		sum -= n;
		d[n] = 1;
		n--;
	}
	cout << index << "\n";
	for (int i = 1; i <= cur; i++) {
		if (d[i]) cout << i << " ";
	}
	cout << "\n" << cur - index << "\n";
	for (int i = 1; i <= cur; i++) {
		if (!d[i]) cout << i << " ";
	}
}

int main() {
	ll t;
	cin >> t;
	solve(t);
}        
