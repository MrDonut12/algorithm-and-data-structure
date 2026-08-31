#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n;
    cin >> n;

    ll sum = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << max(sum, 2 * mx);
}
