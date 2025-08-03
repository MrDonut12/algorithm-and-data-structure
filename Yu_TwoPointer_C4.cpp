#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e6 + 256;
ll n, k, a[N];
ll result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    unordered_map<ll, ll> freq;
    int l = 1;

    for (int r = 1; r <= n; ++r) {
        ++freq[a[r]];

        while (freq.size() > k) {
            --freq[a[l]];
            if (freq[a[l]] == 0)
                freq.erase(a[l]);
            ++l;
        }

        result += (r - l + 1);
    }

    cout << result;
    return 0;
}

