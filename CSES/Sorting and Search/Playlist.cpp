#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define ll long int
using namespace std;
const ll N = 5e6 + 10;
ll in = 0, n, A[N];
ll j = 1, res = 0;
map <ll, bool> B;
map <ll, ll> F;
int main() {
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (ll i = 1; i <= n; i++) {

        while (B[A[i]]) {
            B[A[j]] = 0;
            j++;
        }
        B[A[i]] = 1;
        // F[i] = max(F[i], i - j);
        res = max(res, i - j + 1);
    }

    cout << res;
}

