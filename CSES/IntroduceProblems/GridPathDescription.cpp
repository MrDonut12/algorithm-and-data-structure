// Tư duy Pruning còn yếu nghề, cần rèn thêm
// Loạn cái vụ từ dfs -> backtrack, lỏ cái visited mà loay hoay cả ngày k bt tại sao sai =)))))))
// Cân nhắc kỹ thứ tự thực thi khi backtrackking
// Bài này là backtracking nhưng về cơ bản thử hết thì tốn tận 4^49, TLE là cái chắc, càng nhiều '?' khả năng TLE càng cao, vì thế ta hướng tiếp cận của bài này là pruning
// Trong bài trình bày kỹ 3 ý tưởng prunning, đọc code không giải thích thêm


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back

const ll N = 2e5 + 1103;
const ll M = 7;

ll arr[M + 5][M + 5], answer;
char dir[] = {'L', 'D', 'R', 'U'};
ll dx[] = {0, 1, 0, -1};
ll dy[] = {-1, 0, 1, 0};
bool visited[M + 1][M + 1];

string path = "????????????????????????????????????????????????";

bool check(int x, int y){
    return 1 <= x && x <= M && 1 <= y && y <= M;
}

void dfs(int x, int y, int step) {
    visited[x][y] = true;

    // pruning 1
    if (x == M && y == 1 || step == M * M) {
        answer += (x == M && y == 1 && step == M * M);
        visited[x][y] = false;
        return;
    }

    // pruning 2
    if (
        (!check(x - 1, y) || visited[x - 1][y]) && (!check(x + 1, y) || visited[x + 1][y]) &&
        (check(x, y - 1) && !visited[x][y - 1]) && (check(x, y + 1) && !visited[x][y + 1])
    ) {
        visited[x][y] = false;
        return;
    }

    // pruning 3
    if (
        (check(x - 1, y) && !visited[x - 1][y]) && (check(x + 1, y) && !visited[x + 1][y]) &&
        (!check(x, y - 1) || visited[x][y - 1]) && (!check(x, y + 1) || visited[x][y + 1])
    ) {
        visited[x][y] = false;
        return;
    }

    for (int i = 0; i < 4; i++) {

        if (path[step] != '?' && path[step] != dir[i]) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!check(nx, ny)) continue;
        if (visited[nx][ny]) continue;

        dfs(nx, ny, step + 1);
    }

    visited[x][y] = false;
}


void init() {
    dfs(1, 1, 1);
}
int main() {
    cin >> path;
    path = "#" + path;
    init();
    cout << answer << "\n";
}
