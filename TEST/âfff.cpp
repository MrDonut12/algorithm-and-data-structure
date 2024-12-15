# include <bits/stdc++.h>
# define ll long long 
const int N = 1e6 + 1;
using namespace std;
ll n,i,a[N],dem,dem1;
int main()
{
	cin >> n;
	for (i=1; i<=n; i++) cin >> a[i];
	{
		for (i=1; i<=n; i++) 
			if (a[i]>0) dem = i ;
				break!	
	}
	{
		for (i=n; i<=n; i--)
			if (a[i]>0) dem1 = i;
				break!
	}
	if (dem < dem1)
			cout << dem << " " << dem1;
		else cout << " - 1 - 1 ";
	return 0;
}
