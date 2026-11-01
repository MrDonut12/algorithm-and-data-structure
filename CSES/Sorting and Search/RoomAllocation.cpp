#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back

const ll N = 2e5 + 1103;
const ll M = 1103;

struct ii {ll st, ed, index;};

ii arr[N];
ll ans[N];

bool cmp (ii a, ii b) {
    if (a.st == b.st) return a.ed < b.ed;
    return a.st < b.st;
}
int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].st >> arr[i].ed;
        arr[i].index = i;
    }

    sort(arr + 1, arr + 1 + n, cmp);

    priority_queue <pair<ll,ll>, vector <pair<ll, ll>>, greater<pair<ll,ll>>> pq;
    ll room = 1;

    pq.push({arr[1].ed, room});
    ans[arr[1].index] = room;
    for (int i = 2; i <= n; i++) {
        pair <ll, ll> current = pq.top();
        if (current.fi < arr[i].st) {
            pq.pop();
            pq.push({arr[i].ed, current.se});
            ans[arr[i].index] = current.se;
        } else {
            pq.push({arr[i].ed, ++room});
            ans[arr[i].index] = room;
        }
    }
    cout << room << "\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

}
