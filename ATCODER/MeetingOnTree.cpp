#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define fi first
#define se second
#define pb push_back
#define ii pair <ll, ll>


const ll N = 2e5 + 1103;
ll arr[16][6], a[N], cnt;
ll mark[16];
ll n, q;

void solve(int t, int x = 0) {
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 5; j++) {
                if (arr[a[i]][j*3] % 3 == 0) {
                    cnt++;
                    mark[a[i]] = 1;
                    break;
                }
            }
        }
        cout << cnt << " ";
        return ;
    }
    for (int i = 0; i <= 5; i++) {
        if (arr[x][i*3] % 3 == 0) {
            if (mark[x] == 0) {

            }
            cout << ++cnt << " ";
            return ;
        }
    }
    cout << --cnt << " ";
    return ;
}
int main(){
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < 16; i++) for (int j = 0; j < 6; j++) { arr[i][j] = (i ^ j); }
    solve(1);
    while (q--) {
        ll p, x;
        cin >> p >> x;
        a[p] = x;
        solve(2, x);
    }

}
