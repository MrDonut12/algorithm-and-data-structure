#include <bits/stdc++.h>
#define NAME "review."
#define Times fo<<"\nTime: "<<clock()/(double)1000<<" sec"
using namespace std;
int n,k,vc,pos,p;
char c;
string s;
int t[26]={0},addr[26]={0},cur[26]={0};
int main() {    freopen("input.txt", "r", stdin);
freopen("sol.txt", "w", stdout);
    cin>>k>>n;
    vector<string> w;
    for(int i=0; i<k; ++i) {
        cin>>s; ++t[s[0]-97];
        w.push_back(s);
    }
    sort(w.begin(),w.end());
    for(int i=0; i<26; ++i) if(t[i]) addr[i]=p, p+=t[i];
    for(int i =0; i<n; ++i) {
        cin>>c; vc=c-97;
        pos=addr[vc]+cur[vc];
        cur[vc]=(cur[vc]+1)%t[vc];
        cout<<w[pos]<<'\n';
    }
}
