#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int bitin = 0, bitup = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') ++bitup;
			else ++bitin; 
		}
		
		int displace = max(bitin, bitup) - min(bitin, bitup);
		if (displace & 1) cout << "NO\n";
		else {
			if (displace/2 == k) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
