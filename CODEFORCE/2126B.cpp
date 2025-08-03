#include <bits/stdc++.h>
using namespace std;
#define div /
#define ll long long

const ll N = 2e5 + 276;
ll a[N];
string s;
void solve() {
	int n, k;
	cin >> n >> k;
	for  (int i  = 0; i < n; ++i) {
		cin  >> a[i];
	}
	int res = 0, cnt = 0;
	
	bool takebreak = false;
	for (int i =0 ; i< n; i++) {
		if (a[i] == 0 && takebreak == false) cnt++;
		else if (a[i]  == 0  && takebreak == true) {
			takebreak = false;	
		}
		else if (a[i] == 1) {
			cnt = 0;
			takebreak = false;
		}
		if (cnt >= k) cnt = 0, ++res, takebreak = true; 
	}
	
	cout << res << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
