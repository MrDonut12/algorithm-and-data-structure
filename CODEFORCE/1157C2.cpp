#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

ll n, a[N];
map<ll, ll> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    string answer = "";
    ll l = 0, r = n - 1, curr = 0;
    while (l <= r) {
        bool modifier = false;
        if (l == r) {
            if (a[l] > curr) answer += "L";
            break;
        }

        if (a[l] == a[r] && a[l] > curr) {

            curr = a[l];
            char key;
            int nleft = 1, nright = 1;
            ll currin = a[l];
            for (int i = l + 1; i < r; i++) {
                if (a[i] > currin) {
                    nleft++;
                    currin = a[i];
                } else break;
            }
            currin = a[r];
            for (int i = r - 1; i > l; i--) {
                if (a[i] > currin) {
                    nright++;
                    currin = a[i];
                } else break;
            }

            if (nleft >= nright) key = 'L'; else key = 'R';
            for (int i = 1; i <= max(nright, nleft); i++) answer += key;
            break;
        }

        if (a[l] < a[r]) {

            if (a[l] > curr) {
                curr = a[l];
                l++;
                answer += "L";
                modifier = true;
            } else {
                if (a[r] > curr) {
                    curr = a[r];
                    r--;
                    answer += "R";
                    modifier = true;
                }
            }
        }

        if (a[r] < a[l]) {
            if (a[r] > curr) {
                curr = a[r];
                r--;
                answer += "R";
                modifier = true;
            } else {
                if (a[l] > curr) {
                    curr = a[l];
                    l++;
                    answer += "L";
                    modifier = true;
                }
            }

        }

        if (!modifier) {
            break;
        }
    }
    cout << answer.size() << "\n" << answer << "\n";
}
