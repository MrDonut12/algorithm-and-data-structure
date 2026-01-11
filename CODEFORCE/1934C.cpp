#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll,ll>;

bool inside(ll x, ll y, ll n, ll m) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

pii solve_mine(ll n, ll m) {
    ll d1, d2, d3;

    cout << "? 1 1" << endl; cout.flush();
    cin >> d1;


    cout << "? 1 " << m << endl; cout.flush();
    cin >> d2;

    cout << "? " << n << " 1" << endl; cout.flush();
    cin >> d3;

    ll x = (d1 - d2 + m + 1) / 2;
    ll y = (d1 + d2 - m + 1) / 2;

    if (!inside(x, y, n, m)) {
        x = n - d3;
        y = d1 - (n - x) + 1;
    }

    return {x, y};
}

int main() {


    int t; cin >> t;
    while(t--) {
        ll n,m;
        cin >> n >> m;

        pii mine = solve_mine(n,m);

        cout << "? " << mine.first << " " << mine.second << endl; cout.flush();
        ll d; cin >> d;

        if(d == 0) {
            cout << "! " << mine.first << " " << mine.second << endl; cout.flush();
        } else {
            cout << "? " << n - mine.first + 1 << " " << m - mine.second + 1 << endl; cout.flush();
            ll d2; cin >> d2;
            if(d2 == 0) cout << "! " << n - mine.first + 1 << " " << m - mine.second + 1 << endl;
            else cout << "! " << mine.first << " " << mine.second << endl;
        }
    }
}

