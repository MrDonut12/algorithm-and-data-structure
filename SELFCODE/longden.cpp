
#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct ii {
  ll curr, total;
};

struct group {
  ll g, lo;
};

struct SegmentTree {
  int n;
  vector<int> st;

  SegmentTree(int _n) {
    n = _n;
    st.assign(4 * n + 5, 0);
  }

  void update(int id, int l, int r, int pos) {
    if (l == r) {
      st[id]++;
      return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid)
      update(id * 2, l, mid, pos);
    else
      update(id * 2 + 1, mid + 1, r, pos);

    st[id] = st[id * 2] + st[id * 2 + 1];
  }

  int query(int id, int l, int r, int u, int v) {
    if (v < l || r < u)
      return 0;
    if (u <= l && r <= v)
      return st[id];

    int mid = (l + r) / 2;
    return query(id * 2, l, mid, u, v) + query(id * 2 + 1, mid + 1, r, u, v);
  }
};

void solve() {
  ll n, q;
  cin >> n >> q;

  ll a[n];
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<group> cur, nxt;

  SegmentTree seg(n);
  vector<int> ans(q);

  vector<vector<pair<int, int>>> byR(n + 1); // byR[R] = {(L, id)}
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    byR[r].push_back({l, i});
  }

  for (int r = 0; r < n; r++) {
    nxt.clear();
    nxt.push_back({a[r], r});
    for (auto &p : cur) {
      ll g = __gcd(p.g, a[r]);
      if (g == nxt.back().g)
        nxt.back().lo = p.lo;
      else
        nxt.push_back({g, p.lo});
    }

    swap(cur, nxt);

    int hi = r;
    for (auto &p : cur) {
      ll l = (ll)r - p.g + 1;
      if (l >= p.lo && l <= hi)
        seg.update(1, 0, n - 1, l - 1); // đoạn (l, r) hài hòa
      hi = p.lo - 1;
    }
    for (auto &qq : byR[r]) {
      ans[qq.second] = seg.query(1, 1, n, qq.first, r);
    }
  }

  for (int x : ans)
    cout << x << "\n";

  //             cout << seg.query(1, 0, n - 1, 6, 7).total << "\n";
  //
  //             cout << seg.query(1, 0, n - 1, 7, 8).total << "\n";
  //
  //
  //             cout << seg.query(1, 0, n - 1, l - 1, r - 1).total << "\n";

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--)
    solve();
}
