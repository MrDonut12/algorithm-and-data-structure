#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, string s = "") {
    if (n == 0) {
        cout << s << "\n";
        return ;
    }

    solve(n - 1, s + "0");
    solve(n - 1, s + "1");

}

int main() {
    int n;
    cin >> n;
    solve(n, "");
}
