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
#define test 100
signed main() {
    srand(time(NULL));
    ll ac  = 0, yes = 0;
    forto(i, 1, test) {

        ofstream fi("input.txt");
        ll t = rd(1, 6);
        fi  << t << endl;
       while(t--) {
           ll n = rd(1e3 - 100, 1e4);
           ll a = rd(1, 10);
           ll b = rd(1, 10);
           fi << n << " " << a << " " <<b <<  endl;
       }

       string s;
       ifstream fo("A.txt");
       fo >> s;
       if (s == "Yes") yes++;
        // test
        system("A.exe");
        system("B.exe");
        cout << "TEST " << i << "______________________\n";
        if (system("fc A.txt B.txt") == 0) {
            cout << "AC!!" << endl; ac++;
        } else {
            cout << "WA" << endl;
        }
    }
    cout << "AC TEST: " << ac << "/" << test << endl;
    cout << "YES: " << yes << "/" << test << endl;
}
