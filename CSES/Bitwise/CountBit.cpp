#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define se second
#define ii pair <ll, ll>
const ll N = 2e5 + 1103;
const ll M = 1103;

ll n;

const int MAXN = 60;
ll C[MAXN + 1][MAXN + 1];

void initPascal() {
    for (int n = 0; n <= MAXN; n++) {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++)
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
    }
}

ll mem[N];
void solve() {
    cin >> n;
    ll dis = 0;
    ll ans = 0;
    ll cnt = 0;
    initPascal();
    while (n) {
        if (n & 1) {
            mem[++cnt] = 1;
            ans += 1;
            for (int i = 1; i <= dis; i++) {
               ans += C[dis][i] * i;
               mem[cnt] += C[dis][i];
            }

            mem[cnt] += mem[cnt - 1];
            ans += mem[cnt - 1];

        }
        ++dis;
        n >>= 1;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
