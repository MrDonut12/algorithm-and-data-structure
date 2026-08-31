#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll N = 2e5 + 1103;
map <ll, ll> cnt;
ll a[N], k;
bool stop = false;
void solve(ll n, ll d, ll diff, string s = "") {

    if (stop) return;
    if (d == n + 1) {

        for (auto it : cnt) {
            if (it.second == 0) return ;
            if (diff != it.second) {
                return ;
            }
        }

        cout << s << "\n";
        stop = true;
        return ;
    }
    for (int i = 1 ; i <= k ; i++) {
        cnt[i] += a[d];
        solve(n, d + 1, cnt[i], s + to_string(i) + " ");
        cnt[i] -= a[d];
    }

}

int main() {
    int n;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cnt[i] = 0;
    for (int i = 1 ; i <= n; i++) {
        cin >> a[i];
    }
    solve(n, 1, 0);
}
