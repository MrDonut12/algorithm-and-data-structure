#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll t, n, m;
const ll N = 2e5 + 276;
ll a[N], b[N];


int supper_bound();


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    ll answer = 1e18, l = 0;
    for (int r = 0; r < m; r++) {
        while (a[l] > b[r] && l < n) {
            answer = min(answer, b[r] - a[l]);
            l++;
        }
    }
}
