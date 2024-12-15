#include <bits/stdc++.h>
#define ll long long

using namespace std;
mt19937 rd(chrono:: steady_clock::now().time_since_epoch().count());

string sum(string a, string b) {
    ll carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if (a.size() < b.size()) {
        a.append(b.size() - a.size(), '0');
    } else {
        b.append(a.size() - b.size(), '0');
    }
    string res;
    for (size_t i = 0; i < a.size(); i++) {
        ll digitSum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = digitSum / 10;
        res.push_back((digitSum % 10) + '0');
    }
    if (carry > 0) {
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
	ll n, k;
	cin >> n;
	char a[n+5][n+5];
	string f[n+5][n+5];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	f[1][0] = "1";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == '*') f[i][j] = "0"; else
			 f[i][j] = sum(f[i - 1][j], f[i][j - 1]);
		}
	}
	
	
	cout << f[n][n];
}
