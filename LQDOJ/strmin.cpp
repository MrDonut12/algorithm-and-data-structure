#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ii pair <ll, ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define forto(i, a, b) for (ll i = a; i <= b; i++)
#define ford(i, a, b) for (ll i = a; i >= b; i--)

const ll N = 2e5 + 1103;
const ll M = 1e3 + 1103;
const ll P = 1e9 + 7;

stack <char> st;
ll n, k; string s;

int main() {
    cin >> k >> s;
    ll rm = s.size() - k;
    for (char c : s) {

        while (rm > 0 && st.size() > 0 && st.top() > c) {
            st.pop();
            rm--;
        }

        st.push(c);
    }

    while (rm > 0) {
        st.pop();
        rm--;
    }

    string result = "";
    while (!st.empty()) {
        result += (st.top());
        st.pop();
    }

    reverse(result.begin(), result.end());
    cout << result;
}
