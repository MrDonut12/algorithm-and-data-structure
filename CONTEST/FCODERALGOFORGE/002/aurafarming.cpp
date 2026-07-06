#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll a[2000000];
int main() {
    a[0] = 0; a[1] = 1;
    for (int i = 2; i < 92; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
   ll t, n;
   cin >> t;
   while (t--) {
       cin >> n;
           cout << a[n+1] << endl;
   }
}
