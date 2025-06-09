#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];

void solve(string s) {
	int n = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
	cout << n << endl;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if ((i + j) * (i + j) == n) {
				cout << i << " " << j << "\n";
				return ;
			}
		}
	}
	cout << -1 << "\n";
	return ;
}
int main(void) {
	int q;
	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		solve(s);
	}
}
