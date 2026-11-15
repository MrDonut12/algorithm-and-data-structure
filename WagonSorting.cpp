#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define ld long double
#define fi first
#define se second
const ll N = 2e5 + 1103;
const ll M = 1103;

ll n, a[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    queue <ll> q1;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        while (!q1.empty() && q1.front() == ans) {
            q1.pop();
            ans++;
        }

        if (a[i] == ans) {
            ans++;
        } else {
            q1.push(a[i]);
        }
    }

    while (!q1.empty() && q1.front() == ans) {
        q1.pop();
        ans++;
    }
    cout << ans - 1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve();
}
