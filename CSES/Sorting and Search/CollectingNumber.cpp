#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
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

stack <ll> st;
vector <ll> a;

void solve() {
    ll n, ans   =0;
    cin >> n;

    vector<ll> a(n);
    forto(i, 0, n-1) cin >> a[i];

    while (a.size() > 1) {
        stack<ll> st;
        vector<ll> b;

        forto(i, 0, a.size() - 1) {
            if (st.empty() || a[i] > st.top()) {
                st.push(a[i]);
            } else {
                b.pb(a[i]);
            }
        }

        a = b;
        ans++;
    }
    cout << a.size();
    cout << ans + (a.size() == 1) << endl;
}


signed main() {
    fastIO;
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}
