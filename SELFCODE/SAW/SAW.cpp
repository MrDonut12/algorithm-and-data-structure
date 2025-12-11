#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e3 + 276;
string a[M][M];
void solve() {
	freopen("input.txt", "r", stdin);
	freopen("saw.txt", "w", stdout);
	int n; cin >> n;
	string s;
	cin.ignore();
	getline(cin, s);
	bool rerv = true;
	int co = -1;
	for (int i = 0; i < s.size(); i++) {
		if (rerv) {
			co++;
		} else {
			co--;
		}
		
		a[co][i] = s[i];
		if (i != 0 && (co == n - 1|| co == 0)) {
			rerv = !rerv;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s.size(); j++) {
			cout << a[i][j];
		}
	}
	cout << "\n";
}
int main() {
	int tt = 1;
//	cin >> tt;
	while (tt--) {
		solve();		
	}

}
