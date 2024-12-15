#include <iostream>
#include <cmath>

using namespace std;

long long tich(long long n) {
    long ans = 1;
    while (n != 0){
    	ans *= n%10;
		n/=10;
	}
    return ans;
}

long long doben(long long n) {
    if (n < 10) return 0;
    return doben(tich(n)) + 1;
}

int main() {
    long long n;
    cin >> n;
    long long  res = -1e18, dobenhientai = -1e18;;
    while(n--){
    	if (long long a = doben(n) > dobenhientai) {
    		dobenhientai = a; 
    		res = n;
    		cout << n << " ";
		}
	}
	cout << res;
}
