#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 1103;
ll f[N];

void solve(ll n, ll k, string s = "") {
    if (k == 0) {
        cout << s << "\n";
        return ;
    }
    for (int i = 1 ; i <= n ; i++) {
        if (f[i] == 1) continue;
        f[i] = 1;
        solve(n, k - 1, s + to_string(i) + " ");
        f[i] = 0;
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    solve(n, k);
}
