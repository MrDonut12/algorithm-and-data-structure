#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a[N];
int main(void) {
	int q;
	cin >> q;
	while(q--) {
		int n;
		cin >> n;
		int dex = 1;
		for (int i = 1; i <= n/2 + (n & 1); i++) {
			a[i] = dex;
			dex += 2;
		}
		dex = 2;
		for (int i = n; i >= n/2 + 2 - !(n & 1); i--) {
			a[i] = dex;
			dex += 2;
		}
		
		for (int i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}
}
