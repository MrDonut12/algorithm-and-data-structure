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
	string s;
	cin >> s;
	map <char, ll> mp;
	for (int i = 0; i < s.size(); i++) mp[s[i]]++;
	int cnt = 0; char X;
	for (auto it: mp) {
		if (it.second % 2 != 0) cnt++, X = it.first;
	}
	string res = "";
	if (cnt >= 2) cout << "NO SOLUTION";
	else {
		for (auto it: mp) {
			for (int i = 1; i <= it.second/2; i++) {
				res+=it.first;
			}
		}
	cout << res;
	if (cnt == 1) {
		cout << X;
	}
	
	for (int i = res.size() - 1; i >= 0; i--) cout << res[i];
	}
}

int main() {
	solve();
}
