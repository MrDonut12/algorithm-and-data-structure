#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
ll powm(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll half = powm(a, b/2);
    if (b & 1) return half * half * a;
    else return half * half;
}
int solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    //cout << n << " " << a << " " << b << endl;
    //cout << "_______________________________" << endl;
    bool check = false;
    ll k = log(n)/log(a);
    //cout << a << " " << b << " " <<k << endl;
    if (b == 1) {
        check = true;
    } else if (a == 1) {
        ll m = (n - 1)/b;
        if (n == m*b + 1) check = true;

    }

    else {for (ll i = 0, fi = powm(a, i); fi <= n; i++) {
        ll se = n - fi;
        //cout << a << "^" << i << " " << fi << endl;

        // check;
        if (se % b == 0) {
            check = true;
            break;
        }
}}
    if (check) cout << "Yes";
    else cout << "No";
        cout << endl;
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("A.txt", "w", stdout);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
