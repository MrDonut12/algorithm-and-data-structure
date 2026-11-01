#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 1103;
ll f[N], n, curr = 1;

struct ii {
    int id;
    ll a;
    ll b;
};

ii a[N], res[N];


bool cmp(ii a, ii b) {
    if (a.a == b.a) return a.b > b.b;
    return a.a < b.a;
}


int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].a >> a[i].b, a[i].id = i;
    sort(a + 1, a + 1 + n, cmp);
    ll maxRange = a[1].b;
    for (int i = 2; i <= n; i++) {
        if (a[i].b <= maxRange) {
            res[a[i].id].b = 1;
        } else res[a[i].id].b = 0;

        maxRange = max(maxRange, a[i].b);
    }
    ll minRange = a[n].b;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i].b >= minRange) {
            res[a[i].id].a = 1;
        } else res[a[i].id].a = 0;
        // cout << minRange << endl;
        minRange = min(minRange, a[i].b);
    }
    for (int i = 1; i <= n; i++) cout << res[i].a << " ";
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << res[i].b << " ";
}
