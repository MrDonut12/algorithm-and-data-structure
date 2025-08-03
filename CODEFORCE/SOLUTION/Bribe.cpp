#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair <ll, ll>

int n, k;
string s;
int preXOR[1000023];
int main(){
	cin >> n >> k;
	cin >> s;
	s = ' ' + s;
	preXOR[1] = 1 << (s[1] - 'a');
	for (int i = 2; i < s.size(); i++) {
		preXOR[i] = preXOR[i - 1] ^ (1 << (s[i] - 'a'));
	}
	
	int ans = 0, l = 1, r = s.size() - 1;
	while (l <= r)
	{
		int g = (l + r) >> 1;
		bool check = false;
		for (int i = 1; i <= n - g + 1; i++) {
			if (__builtin_popcount(preXOR[i + g - 1] ^ preXOR[i - 1]) <= k + 1) {
				check = true;
			}
		} 
		if (check) {
			ans = g + k;
			l = g + 1;
		} else {
			r = g - 1;
		}
	}
	cout << ans;
}

// Duy Khanh
