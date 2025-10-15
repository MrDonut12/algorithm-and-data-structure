#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;
    int a = (n + 1) / 2;     
    int b = n - a;         
    vector< array < int, 3 > > ans;

    for (int z = 1; z <= a; ++z) {
        for (int y = 1; y <= a; ++y) {
            int x = ((y + z - 2) % a) + 1;
            ans.push_back({x, y, z});
        }
    }

    for (int z = 1; z <= b; ++z) {
        for (int y = 1; y <= b; ++y) {
            int x = ((y + z - 2) % b) + 1;
            ans.push_back({x + a, y + a, z + a});
        }
    }

    cout << ans.size() << '\n';
    for (auto &t : ans) {
        cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
    }
    return 0;
}

