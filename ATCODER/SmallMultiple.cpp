#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
ll ans = LLONG_MAX;

ll sumd(string s) {
    ll sum = 0;

    for (int i = 0; i < s.size(); i++) {
        sum += s[i] - '0';
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (ll i = 1; i < 2000000; i++) {
        ll num = n * i;
        ans = min(ans, sumd(to_string(num)));
    }

    cout << ans << '\n';
}
