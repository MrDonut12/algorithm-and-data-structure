#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007

auto _=[](){ios::sync_with_stdio(0); cin.tie(0); return 0;}();

map <ll, ll> m;
ll n, x, r = 1;

int main(){
    for(cin >> n; n--; m[*({ cin>>x; &x; })]++);
    for(auto[_, c]: m) r = r * ++c % M;
    cout << (r + M - 1) % M;
}
