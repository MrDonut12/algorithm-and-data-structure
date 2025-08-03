#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 97;
const int BASE = 256;
const int MOD = 1e9 + 7;

int n;
int hash_left[N], hash_right[N], pow_base[N];
bool notprime[N];
vector<int> primes;

int queryL(int l, int r) {
    return (hash_left[r] - hash_left[l - 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

int queryR(int l, int r) {
    return (hash_right[l] - hash_right[r + 1] * pow_base[r - l + 1] + MOD * MOD) % MOD;
}

bool go(int len) {
    for (int i = 1; i + len - 1 <= n; i++) {
        if (queryL(i, i + len - 1) == queryR(i, i + len - 1))
            return true;
    }
    return false;
}

signed main() {
    string s;
    cin >> n >> s;
    s = ' ' + s;

    pow_base[0] = 1;
    for (int i = 1; i <= n; i++) {
        pow_base[i] = (pow_base[i - 1] * BASE) % MOD;
    }

    for (int i = 1; i <= n; i++) {
        hash_left[i] = (hash_left[i - 1] * BASE + s[i]) % MOD;
    }

    for (int i = n; i >= 1; i--) {
        hash_right[i] = (hash_right[i + 1] * BASE + s[i]) % MOD;
    }

    for (int i = 2; i <= n; i++) {
        if (!notprime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i) {
                notprime[j] = true;
            }
        }
    }

    int l = 0, r = primes.size() - 1, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (go(primes[mid])) {
            ans = primes[mid];
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}

// Duy Khanh

