#include <bits/stdc++.h>
using namespace std;

int main() {
	string s, temp;
	s = "GTGGAGGAGCACCCGGATGTTTGCGAGCGCTTCGCATTGCCAGTATGGGTTATCTCGTGAGGGGAGGGATGAGCATGACTTGTACTCTCTCCATCGACCG";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'A') temp += "A";
		else if (s[i] == 'T') temp += "B";
		else if (s[i] == 'C') temp += "C";
		else if (s[i] == 'G') temp += "D";
	}
	string res = "";
	int cnt = 0;
	for (int i = 0 ; i <temp.size(); i++) {
		if (temp[i] == temp[i + 1]) {
			cnt++;
		} else {
			cnt++;
			if (cnt > 2) res += to_string(cnt) + temp[i];
			else {
				char ch = temp[i];
				for (int j = 1; j <= cnt; j++) res += ch;
			}
			cnt = 0;
		}
	}
	cout <<res;
}
