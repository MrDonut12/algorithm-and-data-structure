#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;
ll ch[N];
ll n;
string s;
map < string, ll > mp;
void backtrack(int idx) {
    if (idx == n) {
    	string ans = "";
        for (int i = 0; i < n; i++) ans += s[ch[i]];
        mp[ans] = 1;
        return;
    }

    for (int i = idx; i < n; i++) {
        swap(ch[i], ch[idx]);
        backtrack(idx + 1);
        swap(ch[i], ch[idx]);
    }
}

int main() {
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) ch[i] = i;

    backtrack(0);
    cout << mp.size() << "\n";
    for (auto it: mp) {
    	cout << it.first << "\n";
	}
    return 0;
}

