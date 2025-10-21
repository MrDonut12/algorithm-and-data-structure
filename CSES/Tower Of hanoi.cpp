#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

vector < pair <ll, ll > > q;
void tr(int n, int A, int B, int C) {
	if (n == 0) return ;
	tr(n - 1, A, C, B);
	cout << A << " " << B << "\n";
	tr(n - 1, C, B, A);
}
int main(){
	int n;
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	tr(n, 1, 3, 2);

}
