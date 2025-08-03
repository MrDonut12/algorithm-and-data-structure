#include <bits/stdc++.h>
using namespace std;
#define triple tuple <int, int, int> 

triple brute(vector <int> digit, int x, int y, bool print = false) {
	
	triple key;
	int xx = x;
	int yy = y;
	if (print) cout << x << y;
	int len = 2;
	while (true) {
		int next = -1;
		for (int i = 0; i <= 9; i++) {
			if ((x + y + i) % 3 == 0 && digit[i] > 0) {
				next = i;
			}	
		}
		
		if (next >= 0) {
			if (print) cout << next;
			digit[next]--;
			x = y;
			y = next;
			len++;
		
		} else {
			break;
		}
	}
	return triple(len, xx , yy);
}

triple ans = triple(0, 0, 0);

int main(){
	vector <int> digit (10);
	
	for (int i = 0 ; i <= 9; i++) {
		cin >> digit[i];
	}
	for (int i = 0; i <= 9; i++) {
		ans = max(ans, triple(1, i, i));
	}
	for (int i = 0; i <= 9; i++) {
		if (digit[i] > 0) {
			digit[i]--;
			for (int j = 0; j <= 9; j++) {
				if (digit[j] > 0) {
					digit[j]--;
					ans = max(ans, brute(digit, i, j));
//					int a, b, c;
//					tie(a, b, c) = ans;
//					cout << a << " " << b << " " << c << endl;
 					digit[j]++;
				}		
			}
			digit[i]++;
		}
	}
	int x = get<1>(ans);
	int y = get<2>(ans);
	digit[x]--;
	digit[y]--;
	brute(digit, x, y, true);
	
}

// Duy Khanh
