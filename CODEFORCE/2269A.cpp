#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <ll, ll>

const ll N = 2e5 + 256;
const ll M = 1e3 + 256;

ll q;

void solve() {
   ll n, k;
   cin >> n >> k;
   cout << ((k - 1) * 2) + (1 << (n - k + 1)) << "\n";
}

int main() {
    q = 1;
    cin >> q;
    while (q--) {
        solve();
    }

}
