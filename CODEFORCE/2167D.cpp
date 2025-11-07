#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int t; 
const ll LIM = 2e6 + 1103;
int main() {
    vector<int> primes;
    vector<bool> is_comp(LIM+1,false);
    for (int i = 2;i <= LIM; i++){
        if (!is_comp[i]){
            primes.push_back(i);
            if ((ll) i*i <= LIM)
                for (int j= i*i; j <= LIM; j += i) is_comp[j]=true;
        }
    }

    cin >> t;
    while(t--){
        int n; cin >> n;
        ll g = 0;
        for (int i=0;i < n;i++){
            ll x; cin >> x;
            if (i==0) g = x;
            else g = __gcd(g, x);
        }
        if (g == 1){
            cout << 2 << '\n';
            continue;
        }
        ll ans = -1;
        for (int p: primes){
            if (g % p != 0){
                ans = p;
                break;
            }
        }
        
        if (ans == -1) cout << -1 << '\n';
        else cout << ans << '\n';
    }
    return 0;
}

