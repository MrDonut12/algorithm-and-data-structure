#include <bits/stdc++.h>
using namespace std;

int tree(int n, int l) {
	if (2*n + 1 == l) return 0;
	for (int i = 1; i <= l; i++){
		cout << "*";
	} cout << endl;
	tree(n, l + 2);

}

int main() {
	int n;
	cin >> n;
	tree(n, 1);
	cout << "*\n*\n*\n*\n";
}
