#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

const ll N = 2e5 + 256;


map <string, bool> mp;
bool check[N];
string s;

void backtrack(string tmp, int step) {
    if (step == s.size()) {
        mp[tmp] = 1;
        return ;
    }

    for (int i = 0; i < s.size(); i++) {
        if (!check[i]) {
            check[i] = true;
            backtrack(tmp + s[i], step + 1);
            check[i] = false;
        }
    }

}

int main() {
    cin >> s;
    backtrack("", 0);
    cout << mp.size() << endl;
    for (auto it : mp) {
        cout << it.first << endl;
    }
}
