#include <bits/stdc++.h>
using namespace std;


void solve() {
	string s;
	cin >> s;
	int n = s.size();
	string s1, s2;
	int dem4 = n/2 + (n&1);
	int dem7 = dem4;
	if (s[0] - '0' <= 4) {
		s1 += "4";
		dem4--;
	} else s1 += "44", dem4-=2;
	
	for (int i = 0; i < dem4; i++) s1 += "4";
	for (int i = 0; i < dem7; i++) s1 += "7";
	
	
	dem4 = n/2 + (n&1);
	dem7 = dem4;
	if (s[0] - '0' <= 4) {
        s2+= "4";
        dem4--;
    } else if (s[0] - '0' > 4 && s[0] - '0' < 7) s2 += "7", dem7--;
    else if (s[0]- '0' > 7) s2 += "44", dem4-= 2;
    
    
	for (int i = 0; i < dem4; i++) s2 += "4";
	for (int i = 0; i < dem7; i++) s2 += "7";
	
	ll a = stoll(s);
	ll b = stoll(s1);
	ll c = stoll(s2);
	
	if (b >= a && c >= a) cout << min(b, c);
	else if (b >= a && c <= a) cout << b;
	else if (b <= a && c >= a) cout << c;
	cout << "\n";	
}


int main(){
	int q;
	cin >> q;
	while (q--) {
		solve();
	}
}
