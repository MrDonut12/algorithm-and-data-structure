#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        long long L, R;
        cin >> L >> R;

        long long count = R / 3 - (L - 1) / 3;

        if (3 >= L && 3 <= R) count--;
        if (9 >= L && 9 <= R) count--;

        cout << count << "\n";
    }

    return 0;
}

