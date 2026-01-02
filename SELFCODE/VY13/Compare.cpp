#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define ii pair<ll, ll>
#define forto(i, a, b) for(ll i = a; i <= b;i ++)
#define fordto(i, a, b) for(ll i = a; i >= b;i --)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0)

const ll N = 2e5 + 256;
const ll M = 2e5 + 256;
const ll P = 1e9 + 7;

using namespace chrono;


ll rd(ll l, ll r) {
	return l + rand() % (r - l + 1);
}

string rd_str(ll sz) {
	string res = "";
	string fig = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0 ; i < sz; i++) {
		ll pos = rd(0, fig.size() - 1);
		res += fig[pos];
	}
	return res;
}
#define test 10
signed main() {
    srand(time(NULL));
    ll ac  = 0;
    forto(i, 1, test) {
        ll n = rd(1e5 - 100, 1e5);
        ll k = rd(1e5 - 100, 1e5);
        ofstream fi("input.txt");
        fi << k << " " << n << endl;
        for (int i = 1; i <= k; i++) {
            string s = rd_str(rd(5, 21));
            fi << s << endl;
        }
        for (int i = 1; i <= n; i++) {
            string c = rd_str(1);
            fi << c << endl;
        }

        // test
        system("Solution.exe");
        system("CY13.exe");
        cout << "TEST " << i << "______________________\n";
        if (system("fc output.txt sol.txt") == 0) {
            cout << "AC!!" << endl; ac++;
        } else {
            cout << "WA" << endl;
        }
    }
    cout << "AC TEST: " << ac << "/" << test << endl;
}
