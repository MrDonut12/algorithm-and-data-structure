#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair <int, int>
#define pb push_back
#define fastIO \
	ios_base::sync_with_stdio(false); \
	cin.tie(nullptr); \
	cout.tie(nullptr);
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
ll n;
set <ll> res;
int main(){
	fastIO;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		res.insert(x);
	}
	cout << res.size();
}
