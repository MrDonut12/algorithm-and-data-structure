#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using u128 = __uint128_t;
const ll MOD = 1000000007LL;

ll modmul(ll a, ll b) { return (ll)((u128)a * b % MOD); }
ll modpow(ll a, ll e) {
    ll r = 1;
    a %= MOD;
    while (e) {
        if (e & 1) r = modmul(r, a);
        a = modmul(a, a);
        e >>= 1;
    }
    return r;
}

u64 mul64(u64 a, u64 b, u64 m) { return (u64)((u128)a * b % m); }
u64 pow64(u64 a, u64 e, u64 m) {
    u64 r = 1;
    while (e) {
        if (e & 1) r = mul64(r, a, m);
        a = mul64(a, a, m);
        e >>= 1;
    }
    return r;
}

bool isPrime64(u64 n) {
    if (n < 2) return false;
    for (u64 p : {2ULL,3ULL,5ULL,7ULL,11ULL,13ULL,17ULL,19ULL,23ULL,29ULL,31ULL,37ULL})
        if (n % p == 0) return n == p;
    u64 d = n - 1; int s = 0;
    while ((d & 1) == 0) { d >>= 1; ++s; }
    u64 bases[] = {2ULL,325ULL,9375ULL,28178ULL,450775ULL,9780504ULL,1795265022ULL};
    for (u64 a : bases) {
        if (a % n == 0) continue;
        u64 x = pow64(a % n, d, n);
        if (x == 1 || x == n-1) continue;
        bool comp = true;
        for (int r = 1; r < s; ++r) {
            x = mul64(x, x, n);
            if (x == n-1) { comp = false; break; }
        }
        if (comp) return false;
    }
    return true;
}

static mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
u64 pollard(u64 n) {
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    while (true) {
        u64 c = uniform_int_distribution<u64>(1, n - 1)(rng);
        u64 x = uniform_int_distribution<u64>(0, n - 1)(rng);
        u64 y = x, d = 1;
        auto f = [&](u64 v){ return (mul64(v, v, n) + c) % n; };
        while (d == 1) {
            x = f(x); y = f(f(y));
            u64 diff = x > y ? x - y : y - x;
            d = __gcd(diff, n);
        }
        if (d != n) return d;
    }
}

void factor(u64 n, map<u64,int>& res) {
    if (n == 1) return;
    if (isPrime64(n)) { res[n]++; return; }
    u64 d = pollard(n);
    factor(d, res);
    factor(n/d, res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    u64 n; int k;
    cin >> n >> k;
    if (n == 1) { cout << 1 << '\n'; return 0; }

    map<u64,int> fac;
    factor(n, fac);

 
    int maxE = 0;
    for (auto &pr : fac) maxE = max(maxE, pr.second);
    vector<ll> inv(maxE + 2);
    for (int i = 1; i <= maxE + 1; ++i) inv[i] = modpow(i, MOD - 2);

    ll ans = 1;
    for (auto &pr : fac) {
        ll pmod = pr.first % MOD;
        int a = pr.second;

        vector<ll> dp(a+1), ndp(a+1);
        dp[a] = 1; 

        for (int step = 0; step < k; ++step) {
            fill(ndp.begin(), ndp.end(), 0);
            for (int e = 0; e <= a; ++e) if (dp[e]) {
                ll share = dp[e] * inv[e+1] % MOD;
                for (int j = 0; j <= e; ++j) {
                    ndp[j] += share;
                    if (ndp[j] >= MOD) ndp[j] -= MOD;
                }
            }
            dp.swap(ndp);
        }

        ll expect = 0, pw = 1;
        for (int e = 0; e <= a; ++e) {
            if (e) pw = modmul(pw, pmod);
            expect = (expect + dp[e] * pw) % MOD;
        }
        ans = modmul(ans, expect);
    }

    cout << ans % MOD << '\n';
    return 0;
}

