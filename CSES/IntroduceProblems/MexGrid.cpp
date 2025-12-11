#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0);
#define forto(i,a,b) for(ll i=(ll)a;i<=(ll)b;i++)
#define fordto(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)



const int M = 113;
int a[M][M];
bitset<M> crow[M], ccol[M];

void solve() {
    int n;
    cin >> n;
    forto(i, 0, n - 1) {
        forto(j, 0,n - 1) {
            int val = 0;
            while (crow[i][val] || ccol[j][val]) val++;
            a[i][j] = val;
            crow[i][val] = 1;
            ccol[j][val] = 1;
        }
    }
    forto(i, 0, n - 1) {
        forto(j,0, n - 1) cout << a[i][j] << " ";
        cout << "\n";
    }
}

signed main() {
    FAST_IO
//freopen("./TEST.INP", "r", stdin);
    //freopen("./TEST.OUT", "w", stdout);
    solve();
    return 0;
}
