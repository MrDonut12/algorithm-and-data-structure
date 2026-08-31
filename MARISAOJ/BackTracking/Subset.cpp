#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, ll k, ll index = 1, string s = "") {
    if (k == 0) {
        cout << s << "\n";
        return ;
    }
    for (int i = index ; i <= n ; i++) {
        solve(n, k - 1, i + 1, s + to_string(i) + " ");
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    solve(n, k);
}
