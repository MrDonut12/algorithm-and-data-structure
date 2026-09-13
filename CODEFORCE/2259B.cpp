

// 1 10 100 1000 100000
// 0 5 50 500 5000
// 2 3 4 5 6 7 8
// 0 1 2 3 4 5 6
// 2 1 0 1 2 3 4
// 0 1 2 1 0 1 2
// 2 1 0 1 2 1 0
// 0 1 2 1 0 1 2
// diff[]: 0 1 1 2 2 3 3 4
// odd -> minus maximum is a[i] / 2 (3 -> 1, 5 -> 2, 7 -> 3, 19 -> 9) to have result is 1
// even -> a[i]/2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1103;
const ll INF = 1e9 + 7;

ll n, m, a[N];
ll prefix[N],cnt[3];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    cnt[0] = cnt[1] = cnt[2] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0 && ((a[i] / 2) % 2 == 0)) cnt[0]++;
        else if (a[i] % 2 == 0 && ((a[i] / 2) % 2 != 0)) cnt[1]++;
        else if (a[i] % 2 != 0) cnt[2]++;
    }
    cout << max(cnt[0], max(cnt[1], cnt[2])) << "\n";
}


int main() {
    int tt;
    cin >> tt;
    while (tt--) {solve();
}}
