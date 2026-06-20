#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, char src, char temp, char dest) {

    if (n == 1) {
        cout << src << " " << dest << "\n";
        return;
    }

    hanoi(n - 1, src, dest ,temp);
    cout << src << " " << dest << "\n";
    hanoi(n - 1, temp, src, dest);
}

int main() {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    hanoi(n, '1', '2', '3');
}
