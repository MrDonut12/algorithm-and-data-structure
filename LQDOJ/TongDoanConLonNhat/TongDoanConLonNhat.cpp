#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
using namespace std;
const ll N = 2e6 + 276;
const ll M = 1e3 + 256;

#define fastIO\
	ios_base::sync_with_stdio(false);\
	cin.tie(nullptr)

ll a[N];
int main() {
	fastIO;
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	ll cur_max = a[1], maxS = a[1];
	for (int i = 2; i <= n;i++) {
		maxS = max(a[i], maxS + a[i]);
		cur_max = max(cur_max, maxS);
	}
	cout << cur_max;
}

