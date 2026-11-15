#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 3303;
char a[N][N];
string dp[N][N];
void solve() {
  ll n, s = 0;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    for (int j = 1; j <= n; j++) {
      a[i][j] = x[j - 1];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        if (i == 1) {
            dp[i][j] = dp[i][j - 1] + a[i][j];
            continue;
        }
        if (j == 1) {
            dp[i][j] = dp[i - 1][j] + a[i][j];
            continue;
        }
        dp[i][j] = min(dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]);
    }
  }
  cout << dp[n][n] << "\n";

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;

  while (t--)
    solve();

  return 0;
}
