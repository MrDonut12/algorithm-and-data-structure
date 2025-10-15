#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e3 + 106;

ll n, m, dist[N][N];
bool check[N][N];
int dx[] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

struct ii {
	int x, y;
};

queue <ii> q;

void solve() {
	ll x, y;
	cin >> x >> y;
	if ((x + y) % 3 == 0 && (2* min(x, y) >= max(x, y))) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
