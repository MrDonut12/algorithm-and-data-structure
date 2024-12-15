#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e3 + 276;
ll n, m, a[N][N], prefix[N][N];
vector <ll, ll> pos;
void solve(){
	ll k, d;
	for (int i =1; i<=n; i++) {
		for (int j = 1; j <= m; j++) {
			 	
		}
	}
}

int main(){
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			prefix[i][j] = a[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
	
	
}
