#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000], prefix[10000];

//1 2 3 4 5

signed main(){
	int n, b, k;
	cin >> n >> k >> b;
	for (int i = 1 ; i <= n; i++)
		cin >> a[i];
	
	prefix[1] = a[1];
	
	for (int i = 2; i <= n; i++) 
		prefix[i] = prefix[i - 1] + a[i];
		
	int pos = (b - 1) % n + 1;
	if (k <= n - pos + 1) 
		cout << prefix[pos + k - 1] - prefix[pos - 1];
	else 
		cout << prefix[n] - prefix[pos - 1] + (((k - (n - pos + 1)))/n) * prefix[n] + prefix[(((k - (n - pos + 1)))%n)];
	
}
// Duy Khanh
