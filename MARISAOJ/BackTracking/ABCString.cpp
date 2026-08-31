#include <bits/stdc++.h>
using namespace std;

#define ll long long

string d = "ABC";

void solve(ll n, string s = "") {

    if (n == 0) {
        cout << s << "\n";
        return ;
    }

    for (int i = 0; i < 3; i++) {
        if (s.size() != 0 && s[s.size() - 1] == d[i]) {
            continue;
        }

        solve(n - 1, s + d[i]);

    }

}

int main() {
    int n;
    cin >> n;
    solve(n);
}
