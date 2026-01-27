#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ci pair <char, ll>
#define endl "\n"
#define deb cout<<"debug\n"
#define fi first
#define se second
#define pb push_back
#define forto(i, a, b) for(int i = a; i <= b; i++)
#define fordto(i, a, b) for(int i = a; i >= b; i--)
#define rep(i, n) for(int i = 1; i <= n; i++)
#define fastIO ios_base::sync_with_stdio(false);\
                    cin.tie(0);

using namespace chrono;
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
const ll INF = 1e9 + 7;

ll a[N], b[N];
ll n, x;
int main() {
    fastIO;
    cin >> n;
    forto(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll val = 1;
    forto(i, 1, n) {
        if (a[i] > val) {
            return cout << val << endl, 0;
        }
        val += a[i];
    }
    cout << val << endl;
}
