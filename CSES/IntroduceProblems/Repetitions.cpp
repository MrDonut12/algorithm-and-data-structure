#include <bits/stdc++.h>
#define ll long long
const ll N = 2e6 + 276;
using namespace std;
string s;
bool check[N];
int main() {
	cin >> s;
	ll res = 0, k = 0;
	for (int i = 0; i < s.size(); i++) {
		k++;
		if (s[i] != s[i + 1]) {
			res = max(res, k);
			k = 0;
		}	
	}
	cout << res;
	return 0;
}
