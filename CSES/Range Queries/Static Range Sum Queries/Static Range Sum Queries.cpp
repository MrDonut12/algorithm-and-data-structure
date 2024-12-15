#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e6  + 276;
ll n, a[N], q;
ll lmax[N], rmin[N];
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
	}
	lmax[1] = a[1];
	for (int i = 2; i <= n; i++) {
		lmax[i] = lmax[i - 1] + a[i];
	}
	while (q--) {
		ll u, v;
		cin >> u >> v;
		cout << lmax[v] - lmax[u - 1] << "\n";
	}
}

