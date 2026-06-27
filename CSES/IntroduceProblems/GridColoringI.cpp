#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
const ll M = 1e3 + 276;
string s;
ll n, m;
char a[M][M], ans[M][M];
char d[] = {'A', 'B', 'C', 'D'};
int main() {
    cin >> n >> m;

    for (int i = 0 ; i < n; i++){
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i + 1][j + 1] = s[j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                if (d[k] != ans[i - 1][j] && d[k] != ans[i][j - 1] && d[k] != a[i][j]) {
                    ans[i][j] = d[k];
                    break;
                }
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << "";
        }
        cout << endl;
    }

}
