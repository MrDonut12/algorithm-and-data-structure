#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Chuy?n s? th?p phân sang nh? phân
string dec_to_bin(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += (n % 2) ? '1' : '0';
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

// Chuy?n s? th?p phân sang bát phân
string dec_to_oct(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += '0' + (n % 8);
        n /= 8;
    }
    reverse(res.begin(), res.end());
    return res;
}

// Chuy?n s? th?p phân sang hex
string dec_to_hex(int n) {
    if (n == 0) return "0";
    string digits = "0123456789ABCDEF";
    string res = "";
    while (n > 0) {
        res += digits[n % 16];
        n /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

// Nh? phân sang s? th?p phân
int bin_to_dec(string s) {
    int res = 0;
    for (char c : s) {
        res = res * 2 + (c - '0');
    }
    return res;
}

// Bát phân sang s? th?p phân
int oct_to_dec(string s) {
    int res = 0;
    for (char c : s) {
        res = res * 8 + (c - '0');
    }
    return res;
}

// Hex sang s? th?p phân
int hex_to_dec(string s) {
    int res = 0;
    for (char c : s) {
        if (isdigit(c))
            res = res * 16 + (c - '0');
        else if (isalpha(c)) {
            c = toupper(c);
            res = res * 16 + (c - 'A' + 10);
        }
    }
    return res;
}

int main() {
	while(true){
    cout << "Chon yeu cau:" << endl;
    cout << "1 - So sang nhi phan" << endl;
    cout << "2 - So sang bat phan" << endl;
    cout << "3 - So sang hex" << endl;
    cout << "4 - Nhi phan sang so" << endl;
    cout << "5 - Bat phan sang so" << endl;
    cout << "6 - Hex sang so" << endl;
    int chon;
    cout << "Nhap lua chon (1-6): ";
    cin >> chon;
    cin.ignore();
    if (chon >= 1 && chon <= 3) {
        int num;
        cout << "Nhap so thap phan: ";
        cin >> num;
        if (chon == 1)
            cout << "Nhi phan: " << dec_to_bin(num) << endl;
        else if (chon == 2)
            cout << "Bat phan: " << dec_to_oct(num) << endl;
        else if (chon == 3)
            cout << "Hex: " << dec_to_hex(num) << endl;
    } else if (chon >= 4 && chon <= 6) {
        string s;
        cout << "Nhap so can doi: ";
        cin >> s;
        if (chon == 4)
            cout << "Thap phan: " << bin_to_dec(s) << endl;
        else if (chon == 5)
            cout << "Thap phan: " << oct_to_dec(s) << endl;
        else if (chon == 6)
            cout << "Thap phan: " << hex_to_dec(s) << endl;
    } else {
        cout << "Lua chon khong hop le." << endl;
    }
}
    return 0;
}
