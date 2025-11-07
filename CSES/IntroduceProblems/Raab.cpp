#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXA = 1e6;
vector<bool> isPrime(MAXA + 1, true);

// Sàng Eratosthenes
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAXA; i++)
        if (isPrime[i])
            for (int j = i * i; j <= MAXA; j += i)
                isPrime[j] = false;
}

struct Fenwick {
    vector<ll> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int i, int v) {
        for (; i <= n; i += i & -i) bit[i] += v;
    }
    ll query(int i) {
        ll s = 0;
        for (; i > 0; i -= i & -i) s += bit[i];
        return s;
    }
};

int main() {
    #ifndef ONLINE_JUDGE
    freopen("TEST.INP", "r", stdin);
    freopen("TEST.OUT", "w", stdout);
    #endif
    sieve();

    int n;
    cin >> n;
    vector<int> A(n);
    for (int &x : A) cin >> x;

    vector<ll> prefix(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int val;
        if (A[i - 1] == 1 || isPrime[A[i - 1]]) val = +1;
        else val = -1;
        prefix[i] = prefix[i - 1] + val;
    }

    // coordinate compression
    vector<ll> all(prefix.begin(), prefix.end());
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());

    auto getId = [&](ll x) {
        return int(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
    };

    Fenwick fen(all.size());
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int id = getId(prefix[i]);
        ans += fen.query(id);
        fen.update(id, 1);
    }

    cout << ans << "\n";
}
