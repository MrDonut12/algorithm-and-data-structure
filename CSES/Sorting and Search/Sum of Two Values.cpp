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


struct ii {
    int val, idx;
};

bool cmp (ii a, ii b) {
    return a.val < b.val;
}


ii a[N], b[N];
ll n, x;

ll search(ll target) {
    ll l = 1, r = n;
    while (l <= r) {
        ll g = (l + r) >> 1;
        if (a[g].val == target) return g;
        if (a[g].val < target) {
            l = g + 1;
        } else {
            r = g - 1;
        }
    }
    return l;
}


int main() {
    fastIO;
    cin >> n >> x;
    rep(i, n) cin >> a[i].val, a[i].idx = i;;
    sort(a + 1, a + 1 + n, cmp);
    rep(i, n) {
        ll pi = search(x - a[i].val);
        if (a[pi].val + a[i].val == x && pi != i) {
            return cout << a[pi].idx << " " << a[i].idx << endl, 0;
        }
    }

    return cout << "IMPOSSIBLE" << endl, 0;

}
