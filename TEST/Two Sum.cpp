#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e6 + 276;
map <ll, ll> mp;
ll n, a[N], target;
int main(){
	cin >> n >> target;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	for (pair <ll, ll>  it : mp) {
		if (it.first > target) {
			if (mp[target - it.first] > 0) {
				cout << it.first << " " << target - it.first;
				break;
			}
		}
	}
}
