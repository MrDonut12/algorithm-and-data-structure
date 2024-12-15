#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
ll n;
using namespace std;
int main(){
//	Hieu cua tong thu 13 va tong cua cong thu 2 va thu 3 cua cac so thoa man dieu kien abc%4 == 0 tu 0 - 500
	vector <ll> a;
	for (int i = 5; i <= 500; i++) if (i % 5 == 0) a.push_back(i);
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
	cout << endl;
	ll s2 = a[0] + a[1];;
	ll s3 = s2 + a[2];
	ll s13 = 0;
	ll te = 0;
	for (int i = 0; i < 13; i++) te++, s13 += a[i];
	cout << s13 - (	s2 + s3);
	cout << s13 << endl;
	cout << endl << te; 
}
