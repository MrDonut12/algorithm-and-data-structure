#include <bits/stdc++.h>
using namespace std;


#define ll long long
const ll N = 2e5 + 276;
vector <ll> index_dif1;
vector <ll> index_dif2;
int main(){
	freopen("bstr.inp", "r", stdin);
	freopen("bstr.out", "w", stdout);
	ll n; string s1, s2;
	cin >> n >> s1 >> s2;
	ll dif_pair1 = 0, dif_pair2 = 0, one = 0, zero = 0;
	for (int i = 0 ; i < n; i++) {
		if (s1[i] != s2[i]) {
			if (s1[i] == '1') dif_pair1++, index_dif1.push_back(i + 1);
			else if (s2[i] == '1')dif_pair2++, index_dif2.push_back(i + 1);
		}
		one += (s1[i] == '1') + (s2[i] == '1');
		zero += (s1[i] == '0') + (s2[i] == '0');
	}
	if ((one % 2 != 0) || (zero % 2 != 0)) {
		return cout << -1, 0;
	}
	
	int index = 0;
	cout << dif_pair1/2 +  dif_pair2/2 + 2 * (dif_pair2 % 2 != 0) << "\n";
	for (int i = 0; i < dif_pair1 - (dif_pair1 % 2 != 0); i += 2) {
		cout << index_dif1[i] << " " << index_dif1[i + 1] << "\n";
	}
	
	for (int i = 0; i < dif_pair2 - (dif_pair2 % 2 != 0); i += 2) {
		cout << index_dif2[i] << " " << index_dif2[i + 1] << "\n";
	}
	
	if (dif_pair1 % 2 != 0) { 
		cout << index_dif1[dif_pair2 - 1] << " " << index_dif1[dif_pair2 - 1] << "\n";
		cout << index_dif1[dif_pair1 - 1] << " " << index_dif2[dif_pair2 - 1] << "\n";
	}
}
