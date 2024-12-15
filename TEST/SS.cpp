#include <bits/stdc++.h>
using namespace std;

int callbyvalue(int n) {
	n = n + 10;
	return n;
}

int callbyreference(int &n) {
	n = n + 10;
	return n;
}

int main(){
	int a, b;
	a = 10;
	b = callbyreference(a);
	cout << a << " " << b;
}
