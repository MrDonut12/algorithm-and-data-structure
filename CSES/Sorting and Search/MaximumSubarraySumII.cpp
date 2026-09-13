#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;
const ll INF = 1e9 + 7;

ll n, m, ans, a[N];
ll prefix[N];


void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    ll l = 0, r = n;
}


int main() {
    solve();
}
