#include <bits/stdc++.h>
using namespace std;


#define ll long long
ll rd(ll l, ll r) {
	return l + rand() % (r - l + 1);
}

string rd_str(ll sz) {
	string res = "";
	string fig = "-qwertyuiopasdfghjklzxcvbnmQWERTYUIOASDFGHJKLZXCVBNM1234567890 ";
	for (int i = 0 ; i < sz; i++) {
		ll pos = rd(0, fig.size() - 1);
		res += fig[pos];
	}
	return res;
}

int main() {
	srand(time(NULL));
	int test = 120;

	for(int i = 1; i <= test; i++) {
		string ou = "\033[36m------------------//TEST " + to_string(i)+ "//------------------\033[0m\n";
		cout << ou;
		ofstream fo("input.txt");
		ll sz = rd(1e5, 1e6);
		string str = rd_str(sz);
		fo << sz << endl << str;
		fo.close();
		system("Solution.exe");
		system("SAW100.exe");
		
		if (system("fc sol.txt saw100.txt") != 0) {
			cout << "\033[31mWRONG ANSWER\033[0m\n";
			break;
			return 0;
		} else cout << "\033[32mACCEPTED\033[0m\n";
		
	}	
	
    cout <<
"\n\n\033[1;32m----------------------------------------------\n\033[0m\n"
"\033[1;36m - ALL TESTS ARE ACCEPTED - CODE PERFECT! - \n\033[0m\n"
"\033[1;32m----------------------------------------------\n\033[0m";

}
