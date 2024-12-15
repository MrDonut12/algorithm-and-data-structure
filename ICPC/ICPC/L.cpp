#include <bits/stdc++.h>
using namespace std;
long long n, a[(int)1e6 + 276], f[(int)1e6 + 276];
int main(){
	cin >> n;for (int i = 1; i < (int)1e6+276; i++) f[i] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], f[a[i]]++;
	long long res = 0;
	for (int i = 1; i < (int)1e6+276; i++) {
		if (f[i] > 1) res += (f[i]*(f[i] - 1))/2, cout << i << " ";
	}
	cout << res;
	return 0;
}
