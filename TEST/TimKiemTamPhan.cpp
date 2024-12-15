#include <bits/stdc++.h>
using namespace std;
 
int tk_tamphan(int l, int r, int key, int ar[])
{
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        if (ar[mid1] == key) {
            return mid1;
        }
        if (ar[mid2] == key) {
            return mid2;
        }
        if (key < ar[mid1]) {
            return tk_tamphan(l, mid1 - 1, key, ar);
        }
        else if (key > ar[mid2]) {
            return tk_tamphan(mid2 + 1, r, key, ar);
        }
        else {
            return tk_tamphan(mid1 + 1, mid2 - 1, key, ar);
        }
    }
    return -1;
}
 
int main()
{
    int l, r, p, key;
    // m?ng dã s?p x?p
    int ar[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
 
    l = 0;
    r = 9;
 
    // key
    key = 5;
 
    // s? d?ng tìm ki?m tam phân
    p = tk_tamphan(l, r, key, ar);
     
    // in k?t qu?
    cout << "Index of " << key
         << " is " << p << endl;
 
    // Key 
    key = 50;
 
    // s? d?ng tìm ki?m tam phân
    p = tk_tamphan(l, r, key, ar);
    // In k?t qu?
    cout << "Index of " << key
         << " is " << p << endl;
}
