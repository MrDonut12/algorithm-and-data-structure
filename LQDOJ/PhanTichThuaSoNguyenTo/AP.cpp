#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

const ll N = 2e6 + 276;

bool scp(ll n) {
    if (n < 0) return false;
    ll a = sqrt(n);
    return (a * a == n);
}

bool PRIMES(int a) {
    if (a < 4) return (a > 1);
    if (a % 2 == 0 || a % 3 == 0) return false;
    for (int i = 5; i * i <= a; i += 6) {
        if (a % i == 0 || a % (i + 2) == 0) return false;
    }
    return true;
}

ll uoc(ll n) {
    ll res = 2; // 1 và n luôn là ước
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) res += 2;
    }
    if (scp(n)) res--;
    return res;
}

void solve(ll n) {
    ll original = n;
    cout << n << " = ";
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i;
            n /= i;
            if (n > 1) cout << "*";
        }
    }
    if (n > 1) cout << n;
    cout << "\nSố ước: " << uoc(original) << "\n";
}

int main() {
    FAST_IO;
    ll n;
    cin >> n;
    solve(n);
    return 0;
}
