#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 1103;
map <ll, ll> flag;
ll a[N];


int main() {
    ll n, ans = 0, j = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], flag[a[i]] = 0;
    for (int i = 1; i <= n; i++) {
        if (flag[a[i]]) {

            while (a[j] != a[i]) {
                flag[a[j]] = 0;
                j++;
            }
            flag[a[j]] = 0;
            j++;
            flag[a[j]] = 1;
            flag[a[i]] = 1;
        } else {
            flag[a[i]] = 1;
        }

        ans = max(ans, i - j + 1);
    }
    cout << ans << "\n";
}
