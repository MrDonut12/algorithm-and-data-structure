#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 256;

int d[26];

int main() {
    string s;
    cin >> s;
    int n = s.size(), mx = 0;
    for (int i = 0; i < n; i++) {
        d[s[i] - 'A']++;
        mx = max(mx, d[s[i] - 'A']);
    }

    if (mx > (n + 1)/2) {
        cout << -1;
        return 0;
    }

    string ans;
    for (int i = 0; i < n; i++) {

        for (int c = 0; c < 26; c++) {
            mx = 0;
            if (d[c] <= 0) continue;
            if (!ans.empty() && ans.back() == char(c + 'A')) continue;

            d[c]--;

            for (int c = 0; c < 26; c++) {
                mx = max(mx, d[c]);
            }

            int remain = n - i - 1;

            if (mx <= (remain + 1)/2) {
                ans += (c + 'A');
                break;
            }

            d[c]++;
        }
    }
    cout << ans << endl;
}
