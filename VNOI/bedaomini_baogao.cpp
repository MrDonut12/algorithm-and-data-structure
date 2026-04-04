#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e6 + 1103;
const ll M = 1e3 + 1103;


void solve() {
    ll C, p, t1, t2, n1, n2;
    cin >> C >> p >> n1 >> n2 >> t1 >> t2;

    ll l = 0, r = C/p, ans = 0;

    while (l <= r) {
        ll st = (l + r) >> 1;
        ll cost = p * st + (st / n1) * t1 + (st / n2) * t2;
        // cout << p << " " << st/n1 << " " << st/n2 << " " << st << " " << cost << endl;
        if (cost <= C) {
            ans = st;
            l = st + 1;
        }
        else {
            r = st - 1;
        }
    }

    cout << ans;
}

int main() {
    solve();
}
