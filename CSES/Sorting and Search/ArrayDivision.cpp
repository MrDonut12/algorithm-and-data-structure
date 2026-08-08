#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 276;
ll n, m, ans, k, t, a[N], pre[N];

int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    ll optiRange = s
}
