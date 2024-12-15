#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ii pair<ll, ll>
#define pb push_back
const ll N = 2e5 + 276;
vector<ii> adj[N];
ll n, m, u, v, s;
const ll INF = 1e9;

int to_int(string s) {
	int a = s[0] - '0';
	for (int i = 1 ; i < s.size(); i++) {
		a = a*10  + (s[i] - '0');
	}
	return a;
}

int main(){
	string s;
	cin >> s;
	n = s.size();
	s  = "*" + s;

	string s1, s2, s3, s4;
	ll l = (n%2 == 0) ? n/2 : n/2 + 1;
	for (int i = 1; i <= n/2; i++) {
		s1 += s[i];
		s3 += s[l + i];
	}
	s4 = s1;
	if (to_int(s4) < to_int(s3)) {
		ll id = 0; bool check = false;
		
		if (s4[s4.size() - 1] == '9') {
			for (int i = s4.size() - 1; i >= 0; i--) {
				if (s4[i] == '9') s4[i] = '0';
				else {
					s4[i] = ((s4[i] - '0') + 1) + '0';
					break;
				}
			}
		}
		else s4[s1.size() -1] = ((s4[s1.size()- 1] - '0') + 1) + '0';
	}
	
	for (int i = 0 ; i < s1.size(); i++) {
		s2 += s1[s1.size() - 1- i];
	}
	if (n % 2 != 0) cout << s1 + s[n/2 + 1] + s2; else cout << s1 + s2;
}
