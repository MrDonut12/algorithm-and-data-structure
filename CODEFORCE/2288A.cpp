#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>

const ll N = 2e5 + 1103;
const ll M = 1103;

namespace bruteforce {

    ll x;
    void solve() {
        cin >> x;

        for (int m = 1; ; m++) {
            bool ok = false;

            for (int c = 0; c <= m; c++) {
                int a = m - c;
                int d = 0;

                for (int i = 1; i <= a; i++)
                    d += max(c - i + 2, 1);

                if (d >= x) {
                    ok = true;
                    break;
                }
            }

            if (ok) {
                cout << m << '\n';
                break;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        bruteforce:: solve();
    }
}
