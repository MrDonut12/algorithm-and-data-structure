#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ii {
    ll w, val;
};

const ll N = 2e6 + 276;
ll n, max_w;
ii a[N];

bool cmp(ii a, ii b) {
    if (a.w == b.w)
        return a.val > b.val;
    return a.w < b.w;
}
int main(){
    cin >> n >> max_w;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].val;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll sum = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i].w < max_w) {
            sum += a[i].w;
            res += a[i].val;
        }
    }
    cout << res;
}