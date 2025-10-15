#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 5e5 + 276;
const ll M = 1e3 + 276;

ll n, q, scp[N], sd[N];
ll stock_pr;
const ll MOD = 1e9 + 7;

void realize_profit(int p) {
	
}

void solve() {
	int option;
	cin >> option;
	if (option == 1) {
		ll p, x;
		cin >> p >> x;
		
		scp[p] += x; 
		
	} else if (option == 2) {
		ll x;
		cin >> x;
		stock_pr += x;
	} else  if (option == 3) {
		ll x;
		cin >> x;
		cout << scp[x] * stock_pr << '\n';
	}
}

int main(){
	cin >> n >> q;
	while (q--) {
		solve();
	}
}
