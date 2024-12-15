#include <bits/stdc++.h>
using namespace std;

int solve(const string &str) {
    int n = str.size();
    vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps.back();
}

int main() {

    string s;
    cin >> s;

    string rs = s;
    reverse(rs.begin(), rs.end());

    string com = s + "#" + rs;

    int pl = solve(com);
    int result = s.size() + (s.size() - pl);

    cout << result << endl;

    return 0;
}

