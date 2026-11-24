#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define ll long long
#define ii pair<ll,ll>

const ll N = 2e5 + 10;
const ll M = 2103;
namespace adhoc {

    string op;
    ll to_ll(string num) {
        ll number = 0;
        for (int i = 0; i < num.size(); i++) {
            number = number * 10 + (num[i] - '0');
        }
        return number;
    }
    string sub(string s, ll l, ll r) {
        string res = "";
        for (int i = l ; i <= r; i++) {
            res += s[i];
        }
        return res;
    }
    void solve() {
        string s;
        cin >> s;
        s = '*' + s;
        ll ans = LLONG_MAX;

        for (int i = 1; i < s.size() - 2; i++) {
            for (int j = i + 1; j < s.size() - 1; j++) {
                ans = min(ans, to_ll(sub(s, 1, i)) + to_ll(sub(s, i + 1, j)) + to_ll(sub(s, j + 1, s.size() - 1)));
                // cout << to_ll(sub(s, 1, i)) + to_ll(sub(s, i + 1, j)) + to_ll(sub(s, j + 1, s.size() - 1)) << " " << sub(s, 1, i) << " " << sub(s, i + 1, j) << " " << sub(s, j + 1, s.size() - 1) << endl;
            }
        }
        cout << ans;
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    adhoc :: solve();
}
