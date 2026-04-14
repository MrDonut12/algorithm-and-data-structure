#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
long long n,m,t,ans=1000000000;
int main() {
cin>>n>>m;
vector<int> a[m+1];
vector<int> b(n+1); b[0]=0;
for(int j=0;j<=m;++j)a[0].push_back(0);
for(int i=1;i<=n;++i)a[i].push_back(0);
for(int i=1; i<=n;++i)
{
for(int j=1;j<=m;++j){cin>>t; b[j]=b[j-1]+t;}
for(int j=1;j<=m;++j) a[i].push_back(a[i-1][j]+b[j]);
}
for(int i = 3;i <=n;++i)
for(int j = 3;j<=m;++j)
{
t=a[i][j]-a[i-3][j]-a[i][j-3]+a[i-3][j-3];
if(ans > t) ans = t ;
}
cout << ans;
}
