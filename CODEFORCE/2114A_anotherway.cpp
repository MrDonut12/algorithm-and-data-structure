#include <bits/stdc++.h>
using namespace std;

int main(){
	int q;
	cin >> q;
	while (q--) {
		int x, index = 1, a[4];
		a[1] = 0;
		a[2] = 0;
		a[3] = 0;
		
		cin >> x;
		int in = 0;
		while (true) {
			if (a[1] == x && a[2] ==x && a[3] == x) 
				break;
			if (index == 4) index = 1;
				
			if (index == 1) {
				a[1] = min(a[2]*2 + 1, a[3]*2 + 1);
				if (a[1] >= x) a[1] = x; 
			} else if (index == 2){
				a[2] = min(a[1]*2 + 1, a[3]*2 + 1);
				if (a[2] >= x) a[2] = x; 
			} else {
				a[3] = min(a[2]*2 + 1, a[1]*2 + 1);
				if (a[3] >= x) a[3] = x; 
			}
//			cout << a[1] << " " << a[2] << " " << a[3] << "\n";
			index++;
			in++;
		}
		cout << in << "\n";
	}
}
