#include <bits/stdc++.h>
using namespace std;
#define div /
#define ll long long

const ll N = 2e5 + 276;
string s;
void solve() {
	cin >> s;
	int minre = 100;
	for (int i = 0; i < s.size(); i++) {
		minre = min(minre, s[i] - '0');
	}
	cout << minre << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
