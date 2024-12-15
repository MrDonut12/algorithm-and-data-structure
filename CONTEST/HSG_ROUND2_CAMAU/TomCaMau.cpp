#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_WEIGHT = 102000;
const ll N = 2e5 + 276;
ll n, a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    bitset<MAX_WEIGHT + 1> dp;
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        dp |= dp << a[i];
    }
    cout << dp.count() - 1 << endl; 

    return 0;
}

