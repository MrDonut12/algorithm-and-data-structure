#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll N = 2e6 + 276;
const ll M = 1e3 + 276;
ll n ;
vector <ll> a;
#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                             \
    cout.tie(nullptr);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);
stack <pair <ll , ll> > f;
int main() {
    fastIO;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

