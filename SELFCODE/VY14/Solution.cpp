#include <bits/stdc++.h>
#define NAME "detection."
#define Times fo<<"\nTime: "<<clock()/(double)1000<<" sec"
using namespace std;
#define fi cin
#define fo cout
int n,m,k;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("sol.txt", "w", stdout);
fi>>k;
for(int i=0; i<k; ++i)
{
cin>>n>>m;
cout<<2*min(n-1,m-1)<<'\n';
}
}
