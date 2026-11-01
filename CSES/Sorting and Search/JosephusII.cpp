#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type, less <int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define ll long long
const ll N = 2e5 + 1103;
ll f[N], n, pos, k;

int main(){

    cin >> n >> k;

    indexed_set idx;
    for (int i = 1; i <= n; i++) {
        idx.insert(i);
    }
    while (!idx.empty()) {
        pos = (pos + k) % idx.size();
        cout << *idx.find_by_order(pos) << " ";
        idx.erase(idx.find_by_order(pos));
    }

}
