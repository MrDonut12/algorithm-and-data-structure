#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;

ll fQ[N];

void solve() {
    string s;
    cin >> s;
    ll answer = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        fQ[i] = fQ[i + 1] + (s[i] == 'Q');
    }

    ll lQ = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            answer += lQ * fQ[i + 1];
        }
        lQ += (s[i] == 'Q');
    }
    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
