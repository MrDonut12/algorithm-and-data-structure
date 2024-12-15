#include <bits/stdc++.h>

using namespace std;
#define ll long long
 const ll N = 2e6 + 276;
 ll n, a[N], k;
 deque <ll> q;
int main() {
//    cin >> n >> k;
//    for (int i = 1; i <= n; i++) cin >> a[i];
	q.push_front(10);
	q.push_front(20);
	q.push_front(30);
	q.push_front(40);
	q.push_front(50);
	
	q.pop_back();
	cout << q.front() << endl;
	cout << q.back() << endl;
	
	return 0;
}

