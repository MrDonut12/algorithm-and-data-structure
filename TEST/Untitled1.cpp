#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << " ";
    for (int i = a; i <= b; i++) {
    	for (int j = a; j <= b; j++) {
    		cout << i*j << " ";
		}
		cout << endl;
	}
}

