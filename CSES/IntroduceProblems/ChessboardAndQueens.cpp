#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e2 + 279; // 8x8
int chessboard[M][M];
ll ans = 0, q;
bool valid(int x, int y) {

    if (chessboard[x][y] == -1) return false;

    for (int i = 1; i <= 8; i++) {

        if (x - i >= 1 && chessboard[x - i][y] == 1) return false;
        if (x + i <= 8 && chessboard[x + i][y] == 1) return false;

        if (y - i >= 1 && chessboard[x][y - i] == 1) return false;
        if (y + i <= 8 && chessboard[x][y + i] == 1) return false;

        if (x - i >= 1 && y - i >= 1 && chessboard[x - i][y - i] == 1) return false;
        if (x + i <= 8 && y + i <= 8 && chessboard[x + i][y + i] == 1) return false;
        if (x - i >= 1 && y + i <= 8 && chessboard[x - i][y + i] == 1) return false;
        if (x + i <= 8 && y - i >= 1 && chessboard[x + i][y - i] == 1) return false;
    }
    return true;
}
void backtrack (int idx) {

    if (idx > 8) {
        ans++;
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (valid(idx, i)) {
            chessboard[idx][i] = 1;
            backtrack(idx + 1);
            chessboard[idx][i] = 0;
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
    #endif

    for (int i = 1; i <= 8; i++) {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.size(); j++) {
            if (inp[j] == '.') chessboard[i][j + 1] = 0;
            else if (inp[j] == '*') chessboard[i][j + 1] = -1;
        }
    }
    backtrack(1);
    cout << ans;
}
