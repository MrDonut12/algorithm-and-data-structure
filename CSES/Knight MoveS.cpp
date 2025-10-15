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

void bfs() {
	dist[1][1] = 0;
	q.push({1, 1});
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for (int i = 1; i <= 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dist[i][j] = -1;
	bfs();
	
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}
