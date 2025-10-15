#include <bits/stdc++.h>
using namespace std;
#define ll ll
const  ll N =  2e5 + 276;
ll n, a[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    ll sl = 0, sr = 0;
    for (int i = 0; i < n / 2; i++) sl += a[i];
    for (int i = n / 2; i < n; i++) sr += a[i];

    cout << abs(sl - sr) << "\n";
    return 0;
}

