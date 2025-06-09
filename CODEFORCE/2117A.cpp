#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
int main(){
	int q;
	cin >> q;
	while (q--) {
		int n, k, x;
		cin >> n >> k;
		bool pop = false, ans = true;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				pop = true;
			}
			
			if (pop && k >= 0) {
				k--;
			}
			
			if (k == -1 && a[i] == 1) {
				ans = false;
			}
		}
		
		if (ans)
			cout << "YES\n";
		else cout << "NO\n";
		
	}
}
