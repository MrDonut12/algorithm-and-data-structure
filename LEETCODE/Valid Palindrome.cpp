#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size();i++) {
            s[i] = tolower(s[i]);
            if (isdigit(s[i]) == 1 || (s[i] >= 'a' && s[i] <= 'z')) res += s[i];
        }
        if (res == "") return true;
        else {
            bool ok = true;
            int i = 0, j = s.size() - 1;
            while (i < s.size()/2) {
                if (res[i] != res[j]) ok = false;
                i++, j--;
            }
            
        return ok;
        }
    }
};

bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size();i++) {
            if  (s[i] >= 'A' && s[i] <= 'Z') s[i] = tolower(s[i]);
            if (isdigit(s[i]) == 1 || (s[i] >= 'a' && s[i] <= 'z')) res += s[i];
        }
        if (res == "" || res.size() == 1) return true;
        else {
            bool ok = true;
            int i = 0, j = res.size() - 1;
            while (i < res.size()/2) {
                if (res[i] != res[j]) ok = false;
                i++, j--;
            }
            return ok;
        
        }
    }


int main(){
    string s = ",,,,,,,,,,,,acva";
    bool res = isPalindrome(s);
    cout << res;
}