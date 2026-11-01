#include <bits/stdc++.h>
#include <fstream>
#include <random>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long
#define ii pair <ll, ll>

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll ran(ll l, ll r) {
    return uniform_int_distribution<ll> (l, r)(rng);
}

signed main() {
    ofstream out("out.txt");
    ll l = 100;
    while(l--) {
        out << ran(1, 100) << endl;
    }
}
