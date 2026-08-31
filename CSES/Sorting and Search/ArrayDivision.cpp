#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 276;
ll n, m, ans, k, t, a[N], pre[N];

bool check(ll X) {
    ll sum = 0;
    int cnt = 1;

    for (ll x : a) {
        if (x > X)
            return false;

        if (sum + x <= X) {
            sum += x;
        } else {
            cnt++;
            sum = x;
        }
    }

    return cnt <= k;
}
int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    ll l = 0, r = pre[n - 1];
    ll rangeX = 0, ans = 0;;
    while (l <= r) {
        ll g = (l + r) >> 1;
        // cout << g << " " << check(g) << endl;
        if (check(g)) {
            rangeX = g;
            r = g - 1;
        } else {
            l = g + 1;
        }
    }

    cout << rangeX << endl;
}
