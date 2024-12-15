#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll k;
    cin >> k;

    ll count = 0;

    // Duy?t qua các d? dài có th? c?a dãy liên ti?p
    for (ll L = 1; L * (L + 1) / 2 <= k; L++) {
        // Ki?m tra xem 2k có chia h?t cho L hay không
        if ((2 * k) % L == 0) {
            ll temp = (2 * k / L - L + 1);
            if (temp > 0 && temp % 2 == 0) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}

