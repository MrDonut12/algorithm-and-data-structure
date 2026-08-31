#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll di[] = {-2, -1, 1, 2, 2, 1, -1, -2};
ll dj[] = { 1,  2, 2, 1, -1, -2, -2, -1};

const ll N = 1e3 + 1103;
ll a[N][N], k, n, m;
ll f[N][N];

bool stop = false;

void solve(ll maxStep, ll currStep, ll ii = 1, ll jj = 1) {

    if (stop) return ;

    if (currStep == maxStep) {
        stop = true;
        return ;
    }

    for (int i = 0 ; i < 8; i++) {
        ll ni = ii + di[i];
        ll nj = jj + dj[i];
        if (ni < 1 || ni > n || nj < 1 || nj > m)
            continue;

        if (f[ni][nj] != 0)
            continue;

        f[ni][nj] = currStep + 1;
        solve(maxStep, currStep + 1, ni, nj);

        if (stop) return ;

        f[ni][nj] = 0;
    }



}

int main() {
    cin >> n >> m;

    f[1][1] = 1;
    solve(n*m, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << f[i][j] << " ";
        }
        cout << "\n";
    }
}
