#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair <ll, ll>
#define endl "\n"
const ll N = 1e3 + 276;
ll n, m, res = 0;
string b[N], a[N][N];
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, 1, 0, -1};
bool check[N][N];
void dfs(int x, int y) {
	
	check[x][y] = true;
	for (int i = 0; i < 4; i++) {
		ll x1 = x + dx[i];
		ll y1 = y + dy[i];
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && check[x1][y1] == false && a[x1][y1] == ".") {
			dfs(x1, y1);
		}
	}
} 
int main(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> b[i];
		
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j + 1] = b[i][j];
		}
	}
 
	ll res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == "." && check[i][j] == false) {
				dfs(i, j);
				res++;
			}
		}
	}
	
	cout << res;
}
