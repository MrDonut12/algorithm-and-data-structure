#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const ll N = 2e6 + 276;
ll n, m, a[N];
bool snt(ll x) {
	if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0) return false;
	for (int i =  5; i *i <= x; i+=6) {
		if (x % i == 0 || x % (i + 2) == 0) return false;
	}
	return true;
}

int d[] = {2, 3, 5, 7};
bool cal(long long x) {
    if (x == 0) return false;
    
    int i = 0;
    while (x != 1 && i < 4) { 
        if (x % d[i] == 0) {
            x /= d[i];
        } else i++;
        if (isPrime(x) && x > 7) return false;
    }
    return x == 1;
}

int tknp(ll l, ll r, ll target) {
	while (l <= r) {
		int g = (l + r) /2;
		if (a[g] == target) return g;
		if (a[g] < target) l = g + 1;
		else  r = g - 1;
	}
	return l;
}

//2 5 6 9 20 => 5;
int main(){
	freopen("Pretty.inp", "r", stdin);
	freopen("Pretty.out", "w", stdout);
	cin >> n; ll k = 0;
	for (int i = 1; i <= n; i++ ) {
		ll x; cin >> x;
		if (cal(x)) a[++k] = x;
	}
	sort(a + 1, a + 1 + k);
	a[k + 1] = INT_MAX;
	ll q; cin >> q;
	while (q--) {
		ll s; cin >> s;
		ll res = tknp(1, k, s);
//		cout << res << endl;
		if (s < a[res]) cout << --res << endl; 
		else cout << res << endl;
	}
	return 0;

}
