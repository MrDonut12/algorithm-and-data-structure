#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;

ll n, m, k, ans = LLONG_MAX, adj[M][M];
ll dist[N], check[N];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    function <void(int)> backtrack = [&](int curr) {
        if (curr == n + 1) {
            ll curr_answer = 0;
            for (int i = 2; i <= n; i++) {
                if (adj[dist[i - 1]][dist[i]] == 0) {
                    return ;
                }
                curr_answer += adj[dist[i - 1]][dist[i]];
            }
            curr_answer += adj[dist[n]][dist[1]];
            ans = min(curr_answer, ans);
            return ;
        }

        for (int i = 1; i <= n; i++){
            if (check[i]) continue ;
            dist[curr] = i;
            check[i] = 1;
            backtrack(curr + 1);
            dist[curr] = 0;
            check[i] = 0;
        }
    };

    backtrack(1);
    cout << ans << "\n";
}

int main(){
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}
