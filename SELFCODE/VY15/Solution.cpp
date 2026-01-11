#include <bits/stdc++.h>
#define Times fo<<"\nTime: "<<clock()/(double)1000<<" sec"
#define NAME "cards."
using namespace std;
#define fi cin
#define fo cout
int n,k,rmd=0,s=0,f[12]={0,0,4,4,4,4,4,4,4,4,16,4};
int main()
{freopen("input.txt", "r", stdin);
freopen("sol.txt", "w", stdout);
fi>>n;
for(int i=0;i<n;++i)
{
fi>>k;
s+=k; --f[k];
}
k=21-s;
for(int i=k+1; i<12; ++i)rmd+=f[i];
if(52-n-rmd> rmd) fo<<"DRAW"; else fo<<"STOP";

}
