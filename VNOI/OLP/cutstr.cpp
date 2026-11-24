#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ii pair<ll,ll>

const ll N = 2e5 + 10;
const ll M = 2103;
namespace adhoc {
    bool dp[M][M];

    void initdp(string s) {
        ll n = s.size();
        for (int i = 0; i < n; i++) {
           dp[i + 1][i + 1] = 1;
           if (i < n - 1) dp[i + 1][i + 2] = (s[i] == s[i + 1]);
        }
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n - len; i++) {
            dp[i + 1][i + len + 2] = (s[i] == s[i + len + 1]) * (dp[i + 2][i + len + 1]);
            }
        }

    }
    bool check(string s, ll len[], ll k) {
        ll index = 0;
        ll cnt = 0;
        for (int i = 1; i <= k; i++) {
            ll currLen = len[i];
            for ( ; index < s.size(); ) {
                if (dp[index + 1][index + currLen]) {
                    cnt++;
                    cout << s.substr(index, len[i]) << endl;;
                    index = index + currLen;
                    if (index >= s.size()) {
                        return (cnt == k);
                    }
                    break;
                }
                index++;
            }
        }
        return (cnt == k);
    }

    void solve() {
        string s;
        ll t;
        cin >> s;
        initdp(s);
        cin >> t;
        while (t--) {
            ll k; cin >> k;
            ll len[k + 1];
            for (int i = 1; i <= k; i++) {
                cin >> len[i];
            }

            cout << (check(s, len, k)  ? "YES" : "NO") << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    adhoc :: solve();
}
