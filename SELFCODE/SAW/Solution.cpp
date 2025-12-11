#include<bits/stdc++.h> 
#define NAME "saw." 
#define Times cerr<<"\nTime: "<<clock()/(double)1000<<" sec" 
using namespace std; 

int n,ls,k=0,p,q,u; 
string s,ans; 
int main() 
{ 
freopen("input.txt", "r", stdin);
freopen("sol.txt", "w", stdout);
cin>>n; 
getline(cin,s);getline(cin,s); ls=s.size(); 
ans=s; 
for(int i=0;i<n;++i) 
{ 
p=2*(n-i-1); q=i<<1; ans[k++]=s[i]; u=i; 
while(1) 
{ 
if(u+p>=ls)break; 
if(p>0)u+=p, ans[k++]=s[u]; 
if(u+q>=ls)break; 
if(q>0)u+=q, ans[k++]=s[u]; 
} 
} 
cout<<ans; 
Times; 
} 
