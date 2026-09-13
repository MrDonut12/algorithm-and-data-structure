#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    string s;

    if (!getline(cin, s)) {
        cout << -1;
        return 0;
    }

    if (!(cin >> x)) {
        cout << -1;
        return 0;
    }

    if (x <= 0 || x > 25) {
            cout << -1;
            return 0;
    }


    ll a, b;
    a = 0;
    b = x;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i]) || isalpha(s[i])) {

                ll curr = a + b;
                a = b;
                b = curr;
                if (curr > 25) {
                    curr = 1;
                    a = 0;
                    b = 1;
                }

                if (s[i] >= 'a' && s[i] <= 'z') {
                    if (s[i] + curr >= 'a' && s[i] + curr <= 'z') {
                        cout << char(s[i] + curr);
                    } else {
                        cout << char('a' + (s[i] + curr - 'z') - 1);
                    }
                }

                if (s[i] >= 'A' && s[i] <= 'Z') {
                    if (s[i] + curr >= 'A' && s[i] + curr <= 'Z') {
                        cout << char(s[i] + curr);
                    } else {
                        cout << char('A' + (s[i] + curr - 'Z') - 1);
                    }
                }

                if (s[i] >= '0' && s[i] <= '9') {
                    cout << char((s[i] - '0' + curr) % 10 + '0');
                }


        } else {
            cout << s[i];
        }
    }

}
