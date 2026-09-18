#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5 + 1103;
ll f[N], n, curr = 1, k;

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        f[i] = (i + k);
        if (i + k >= n) {
            f[i] = (i + k) % n + 1;
        }
    }
    while (f[curr] != curr) {
        cout << f[curr] << " ";
        ll update = f[f[curr]];
        f[f[curr]] = -1;
        f[curr] = update;

        curr = update;
    }

    cout << f[curr] << "\n";

}
