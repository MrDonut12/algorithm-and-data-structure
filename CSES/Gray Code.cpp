#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

int g(int n){
	return n ^ (n >> 1);
}
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		int a = g(i);
		for (int j = 0; j <= 20; j++) {
			cout << ((a >> j) & 1);
		}
		cout << "\n";
	}
}
