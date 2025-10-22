#include <bits/stdc++.h>
#define ll int
#define ii pair <ll, ll>
#define endl "\n"
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
#define FastIO \
ios_base::sync_with_stdio(false);\
cin.tie(0);
 
 
using namespace std;
ll n, m, xA, yA, xB, yB;
string a[M][M];
//struct node {
//	int w
//	
//};
 
bool check[M][M];
ll dx[] = {0, -1, 0, 1, 0};
ll dy[] = {0, 0, 1, 0, -1};
string path[] = {"", "U", "R", "D", "L"};
int rpath[M][M]; // luu tru duong di
void bfs(ll x, ll y){
	check[x][y] = 1; 
	queue <ii> q;
	q.push({x, y});
	rpath[x][y] = 0;
	while (!q.empty()) {
		ii t = q.front(); q.pop();
		ll x2 = t.first;
		ll y2 = t.second;
		
		
		for (int i = 1; i <= 4; i++) {
			ll nx = x2 + dx[i];
			ll ny = y2 + dy[i];
			if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !check[nx][ny] && a[nx][ny] != "#") {
				q.push({nx, ny});
				rpath[nx][ny] = i;
				check[nx][ny] = true;
				if (a[nx][ny] == "B") {
					cout << "YES\n";
					string res;
					ll cx = nx, cy = ny;
					while(cx != x || cy != y) {
						ll p = rpath[cx][cy];
						cx -= dx[p];
						cy -= dy[p];
						res += path[p];
					}
					reverse(res.begin(), res.end());
					cout << res.size() << " " << res;
					return;	
				}
			}
		}
	}
	cout << "NO";
	return;
}
int main(){
//	freopen("Test.txt", "r", stdin);
//	freopen("TestS.txt", "w", stdout);
	FastIO;
	cin >> n >> m; //< 1000
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j - 1];
			if (s[j - 1] == 'A') xA = i, yA = j;
		}
	}
	bfs(xA, yA);
	return 0;
}
