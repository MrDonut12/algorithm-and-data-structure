#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
using namespace std;
const ll N = 2e6 + 276;
const ll M = 1e3 + 256;

#define fastIO\
	ios_base::sync_with_stdio(false);\
	cin.tie(nullptr)

bool check(int n) {
	if (n < 4) return false;
	for (int i = 2; i *i  <= n; i++) {
		if (n % i == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	fastIO;
    ll t;
    cin >> t;
    while(t--) {
    	ll n;
    	cin >> n;
    	if (n == 2) {
    		cout << "-1\n";
		} else {
			cout << "1 8";
			for (int i = 1; i <= n - 2; i++){
				cout << " " << i + 1;
			}
			cout << "\n";
		}
	}
    return 0;
}

