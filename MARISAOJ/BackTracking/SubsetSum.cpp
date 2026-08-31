#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
ll a[N], target;
bool stop = false;
bool ok = false;
void solve(ll n, ll curr = 0) {

    if (curr > target || n == -1 || stop) return ;

    if (curr == target) {
        stop = true;
        ok = true;
        return;
    }

    solve(n - 1, curr + a[n]);
    solve(n - 1, curr);

}

int main() {
    int n;
    cin >> n >> target;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
    }
    solve(n);
    if (ok) cout << "YES\n";
    else cout << "NO\n";
}
