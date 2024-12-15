#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
#define TIME    \
     cerr << '\n' << "Time: " << (clock() * 1000.0 / CLOCKS_PER_SEC) << " ms\n";
     
#define FastIO 	\
	ios_base:: sync_with_stdio(false);\
	cin.tie(nullptr);\
	cout.tie(nullptr);

using namespace std;
using namespace chrono;
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
ll n, q, a[M][M], prefix[M][M];
int main(){
	FastIO;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n ; j++) {
			char s; cin >> s;
			a[i][j] = (s ==  '*') ? 1 : 0;
		}
		
	
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
			
	while (q--) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << prefix[x2][y2] + prefix[x1 - 1][y1 - 1] - prefix[x2][y1 - 1] - prefix[x1 - 1][y2];
		cout << endl;
	}
	return 0;
	
}
