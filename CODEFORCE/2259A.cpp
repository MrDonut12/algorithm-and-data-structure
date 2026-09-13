#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;

void solve() {
    ll n, k;
    string s;
    cin >> n >> k >> s;
    ll pre[n + 1];
    s = '*' + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            pre[i] = pre[i - 1] + 1;
        } else pre[i] = pre[i - 1];
    }
    // 8 2
    // 1 2 3 4 5 6 7 8
    // 1   1   1   1

    ll answer = 0;
    for (int i = 1; i <= n; i += k) {
        if (pre[i + k - 1] - pre[i - 1] >= k) {
            answer++;
        }
    }
    cout << answer << "\n";
}

int main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }

}
