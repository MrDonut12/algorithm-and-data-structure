#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 64;

ll x, y;
ll bits[N], numbit;
ll xbit[N], ybit[N];

const ll INF = 1e18 + 7;

void tobit(ll x) {
    string bit;

    while (x) {
        if (x % 2 == 0)
            bit += '0';
        else
            bit += '1';

        x /= 2;
    }

    for (int i = 0; i < bit.size(); i++) {
        if (bit[i] == '1')
            bits[numbit++] = i;
    }
}

void solve() {
    numbit = 0;

    for (int i = 0; i < N; i++) {
        xbit[i] = 0;
        ybit[i] = 0;
        bits[i] = 0;
    }

    cin >> x >> y;

    ll ans = x + y;
    ll op = INF;

    if (x == 0) {
        cout << y << " " << 0 << endl;
        return;
    }

    if ((x ^ y) == ans) {
        cout << ans << " " << 0 << endl;
        return;
    }

    tobit(ans);

    xbit[0] = (1LL << bits[0]);

    for (int i = 1; i < numbit; i++) {
        xbit[i] = xbit[i - 1] + (1LL << bits[i]);
    }

    for (int i = numbit - 1; i >= 0; i--) {
        ybit[i] = ybit[i + 1] + (1LL << bits[i]);
    }

    for (int i = 0; i < numbit; i++) {
        for (int j = 0; j < numbit; j++) {
            if (xbit[i] <= x &&
                ybit[j] > -y &&
                abs(ybit[j] - y) == abs(xbit[i] - x)) {

                op = min(op, abs(ybit[j] - y));
            }
        }
    }

    if (op == INF)
        op = x;

    cout << ans << " " << op << endl;
}

int main() {
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
}
