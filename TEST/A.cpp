#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 201;;
int mat[N][N][N];
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("TEST.INP", "r", stdin);
        freopen("TEST.OUT", "w", stdout);
    #endif

    int p, q, r;
    cin >> p >> q >> r;

    for (int y = 0; y < q; y++)
        for (int x = 0; x < p; x++) {
            string s; cin >> s;
            for (int z = 0; z < r; z++)
                mat[x][y][z] = (s[z] == 'N');
        }

    int ans = 0;
    vector<vector<int>> height(p, vector<int>(q, 0)), dp(p, vector<int>(q, 0));

    for (int z = 0; z < r; z++) {
        for (int x = 0; x < p; x++)
            for (int y = 0; y < q; y++)
                height[x][y] = mat[x][y][z] ? height[x][y] + 1 : 0;

        for (int b = 1; b <= r; b++) {
            for (int x = 0; x < p; x++)
                for (int y = 0; y < q; y++) {
                    if (height[x][y] >= b) {
                        if (x > 0 && y > 0)
                            dp[x][y] = min({dp[x-1][y], dp[x][y-1], dp[x-1][y-1]}) + 1;
                        else dp[x][y] = 1;
                        int a = dp[x][y];
                        ans = max(ans, 4 * a * b);
                    } else dp[x][y] = 0;
                }
        }
    }

    cout << ans;
    return 0;
}
