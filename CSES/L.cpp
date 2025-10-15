#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> exceptions;
    exceptions.push_back(3);

    ll p10 = 1;
    for(int i = 1; i <= 17; i += 2){
        p10 *= 10;  
        exceptions.push_back(p10 - 1);
    }
    p10 = 1;
    for(int i = 1; i <= 16; i++){
        p10 *= 10;  
        if(i % 2 == 0) {
            exceptions.push_back(4 * p10 - 1);
        }
    }

    p10 = 1;
    for(int i = 1; i <= 17; i++){
        p10 *= 10;
        if(i % 2 == 1) {
            exceptions.push_back(7 * p10 - 1);
        }
    }
    sort(exceptions.begin(), exceptions.end());
    exceptions.erase(unique(exceptions.begin(), exceptions.end()), exceptions.end());

    int q;
    cin >> q;
    while(q--){
        ll L, R;
        cin >> L >> R;
        ll cnt = R/3 - (L-1)/3;
        for(ll e : exceptions) {
            if(e < L) continue;
            if(e > R) break;
            cnt--;
        }
        if(cnt < 0) cnt = 0; 
        cout << cnt << "\n";
    }
    return 0;
}

