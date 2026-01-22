#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
return a.second<b.second;
}

pair<long long,long long> a[300005];
int main()
{
int n;
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>a[i].first>>a[i].second;
}
sort(a+1,a+n+1,cmp);
for(int i = 1; i <= n; i++) {
    cout << a[i].first << " " << a[i].second << endl;
}
int dem=0,x=0;
for(int i=1;i<=n;i++)
{
if(a[i].first>=x)
{
dem++;
x=a[i].second;
}
}
cout<<dem;
}
