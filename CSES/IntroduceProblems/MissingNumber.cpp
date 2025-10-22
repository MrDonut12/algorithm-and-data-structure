#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6 + 276;
using namespace std;
ll n, a[N];
bool check[N];
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) cin >> a[i], check[a[i]] = true;
	for (int i = 1; i <= n; i++) if (!check[i]) cout << i << " ";
	return 0;
}
