#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, k;
const ll N = 2e5 + 1103;
ll a[N], b[N];

int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  sort(a, a + n);
  sort(b, b + m);
  int ans = 0;
  ll l = 0, r = 0;
  while (l < n && r < m) {
    if (a[l] - k <= b[r] && b[r] <= a[l] + k) {
      r++;
      l++;
      ans++;
    } else if (a[l] + k > b[r]) {
      r++;
    } else if (a[l] - k < b[r]) {
      l++;
    }
  }
  cout << ans;
}
