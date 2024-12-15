#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
ll n, a[N], k;
int main(){
	cin >> n >> k; ll sum = 0, res = 0;
	for (int i = 1; i <= n ;i ++){
		cin >> a[i];
	}
	sum = a[1];
	for (int i = 1, j = 1; i <= n; ) {
		if (sum > k) {
			sum -= a[j++];
		} else if (sum == k) {
			sum += a[++i];
			res++;
		}
		else {
			sum += a[++i];
		}
		cout << sum << " ";
	}
	cout << res;
}
