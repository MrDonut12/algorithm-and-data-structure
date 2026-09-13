#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long log3(double x) {
    long long ans = 0;
    while (true) {
        x /= 3.0;
        ans++;
        if (x <= 1) break;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--) {
    long long n;
    cin >> n;
    cout << log3(n) << "\n";}
    return 0;

}
