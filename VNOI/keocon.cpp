#include <bits/stdc++.h> 
using namespace std; 
int n; 
map <string, int> mp;

#define fi first
#define se second
int main() 
{ 
	int t;
	cin >> t;
	while (t--) {
		mp["EmTrangTri"] = 0;
mp["KhoBau"] = 0;
mp["DaTan"] = 0;
mp["EmDaoNay"] = 0;
mp["DeQuen"] = 0;
mp["KeThu"] = 0;
mp["HetThoi"] = 0;
mp["ChoToiDiTheo"] = 0;
mp["ChuyenKenh"] = 0;
mp["MotNgayKhongMua"] = 0;
mp["CaHoi"] = 0;
mp["DramaQueen"] = 0;
mp["LanCuoi"] = 0;
mp["ThayChua"] = 0;
mp["Dot"] = 0;
		cin >> n;
		bool flag = true;
		string a[n+101];
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (mp.find(a[i]) != mp.end()) {
			mp[a[i]]++;
			if (mp[a[i]] > 2) {
				flag = false;
			}}
		}
		long sum = 0;
		for (auto it : mp) {
			sum += it.se;
		}
		if (sum >= ((3*n)/4) && flag == true) {
			cout << "YES\n";
		} else cout << "NO\n";
		
	}
} 
