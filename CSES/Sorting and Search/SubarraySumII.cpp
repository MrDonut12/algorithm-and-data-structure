#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 276;
map<ll, ll> cnt;
ll n, m, ans, k, t, a[N], pre[N], x;
int main() {
    cin >> n >> x;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    pre[0] =  a[0];
    for (int i = 1 ; i < n; i++) {
        pre[i] = a[i] + pre[i - 1];
    }

    cnt[0]++; // for case sum 0..i == x
    for (int i = 0; i < n; i++) {
        ll num = pre[i] - x;
        ans += cnt[num];
        cnt[pre[i]]++;
    }

    cout << ans;

}
