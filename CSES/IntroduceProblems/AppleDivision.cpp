#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll N = 2e5 + 276;

ll a[N], n, ans = LLONG_MAX, sum = 0;
bool check[N];
void solve(int step, long long temp) {
    if (step == n) {
        ans = min(ans, abs(temp - (sum - temp)));
        return ;
    }
    solve(step + 1, temp + a[step]);
    solve(step + 1, temp);


}

int main(){
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        sum += a[i];
    }

    solve(0, 0);

    cout << ans << endl;

}
