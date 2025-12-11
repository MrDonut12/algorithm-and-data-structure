#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 1e3 + 276;
string a[M][M], s;
bool check[M*M*2];
void solve() {
	freopen("input.txt", "r", stdin);
	freopen("saw100.txt", "w", stdout);
	for (int i = 0 ; i < M*M*2; i++) check[i] = false;
	int n; cin >> n;
	cin.ignore();
	getline(cin, s);
	int idx = -1;
	int j = 0;
	string ans = "";
	for (int i = (n - 2) * 2 + 1; i >= 1 && j < n; i-=2) {
//		
	
//		cout << i << " " << idx << endl;
		if (j == 0) {
			for (int l = j; l < s.size(); l += i+1) ans+=s[l];
		} else {
			bool xk = true;
//			cout << endl;
			ll l = j;
			while (l < s.size()) {
				if (l < s.size())ans+=s[l];
				
				if (xk) {
					l += i + 1;
				} else l += idx+1;
				xk = !xk;
			}
		}
		j++;
		idx += 2;
	}
	idx = (n - 2) * 2 + 1;
	for(int i = n-1; i < s.size(); i+= idx + 1) ans += s[i];
	cout << ans << endl;
}
int main() {
	solve();
}
