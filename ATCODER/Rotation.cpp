#include <bits/stdc++.h>
#include <sys/types.h>
using namespace std;
#define ll long long
#define ii pair <ll, ll>
#define fi first
#define se second
const ll N = 2e5 + 1103;
ll n, ans;
char a[4][4];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const ll n = 2, m = 3;
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (a[0][0] == a[1][2] && a[0][1] == a[1][1] && a[0][2] == a[1][0]) {
        cout << "YES";
    } else cout << "NO";
}
