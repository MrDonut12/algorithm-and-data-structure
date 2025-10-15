#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq(n);
        for (int i = 0; i < n; i++) cin >> dq[i];

        int ops = 0;
        while (!dq.empty()) {
            if (dq.size() == 1) {
        
                int x = 2; 
                int a = dq.front();
                dq.pop_front();
                dq.push_back(x);
                dq.push_front(a + x);
                ops++; 
            } else {
                int a = dq[0], b = dq[1];
                if (gcd(a,b) == 1 || a % b == 0 || b % a == 0) {
                    dq.pop_front();
                    dq.pop_front();
                    ops++;
                } else {
                    int x = 2;
                    dq.pop_front();
                    dq.push_front(a + x);
                    dq.push_back(x);
                    ops++;
                }
            }
        }
        cout << ops << "\n";
    }
    return 0;
}

