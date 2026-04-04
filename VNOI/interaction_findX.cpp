#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define pb push_back
#define gcd __gcd
#define fi first
#define se second



const ll N = 2e6 + 276;
const ll M = 1e3 + 1103;
ll snt[N];
vector <int> pr;
signed sang() {
	for (int i = 0; i < N; i++) {
		snt[i] = 1;
	}
	snt[1] = snt[0] = 0;
	for (int i = 2; i * i < N; i++) {
		if (snt[i]) {
			for (int j = i * i; j < N; j += i) {
				if (snt[j])
					snt[j] = 0;
			}
		}
	}

	for (int i = 0 ; i < N; i++) {
		if(snt[i]) pr.pb(i);
	}
	return 1;
}
signed main() {
    sang();


}
