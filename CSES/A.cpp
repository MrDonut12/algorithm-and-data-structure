#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct SegTree {
    int n;
    vector<ll> tree;
    SegTree(int n_) : n(n_), tree(4 * n_ + 5, 0) {}

    void update(int id, int l, int r, int pos, ll val) {
        if (l == r) {
            tree[id] += val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(id * 2, l, mid, pos, val);
        else update(id * 2 + 1, mid + 1, r, pos, val);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }

    ll query(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[id];
        int mid = (l + r) / 2;
        return query(id * 2, l, mid, ql, qr) + query(id * 2 + 1, mid + 1, r, ql, qr);
    }

    void add(int pos, ll val) { update(1, 1, n, pos, val); }
    ll sumPrefix(int pos) { 
        if(pos <= 0) return 0;
        return query(1, 1, n, 1, pos); 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        ll C, D;
        cin >> n >> C >> D;
        vector<ll> A(n), B(n);
        for(int i = 0; i < n; ++i) cin >> A[i];
        for(int i = 0; i < n; ++i) cin >> B[i];

        ll L = LLONG_MIN, R = LLONG_MAX;
        for(int i = 0; i < n; ++i){
            L = max(L, A[i] - B[i] - C);
            R = min(R, A[i] - B[i] + D);
        }
        if(L > R){
            cout << -1 << '\n';
            continue;
        }

        vector<pair<ll, pair<ll,ll>>> items(n);
        for(int i=0;i<n;++i) items[i] = {A[i]-B[i], {A[i], B[i]}};
        sort(items.begin(), items.end());

        vector<ll> coordsA, coordsB;
        for(auto &it: items){
            coordsA.push_back(it.second.first);
            coordsB.push_back(it.second.second);
        }
        sort(coordsA.begin(), coordsA.end());
        sort(coordsB.begin(), coordsB.end());
        coordsA.erase(unique(coordsA.begin(), coordsA.end()), coordsA.end());
        coordsB.erase(unique(coordsB.begin(), coordsB.end()), coordsB.end());

        auto idxA = [&](ll v){ return lower_bound(coordsA.begin(), coordsA.end(), v) - coordsA.begin() + 1; };
        auto idxB = [&](ll v){ return lower_bound(coordsB.begin(), coordsB.end(), v) - coordsB.begin() + 1; };

        SegTree fCountA(coordsA.size()), fSumA(coordsA.size());
        SegTree fCountB(coordsB.size()), fSumB(coordsB.size());

        int ptr = 0;
        for(; ptr < n && items[ptr].first <= L; ++ptr){
            int ia = idxA(items[ptr].second.first);
            fCountA.add(ia,1);
            fSumA.add(ia, items[ptr].second.first);
        }
        for(int i=ptr;i<n;++i){
            int ib = idxB(items[i].second.second);
            fCountB.add(ib,1);
            fSumB.add(ib, items[i].second.second);
        }

        vector<ll> cand = {L,R};
        for(auto &it: items){
            if(it.first >= L && it.first <= R) cand.push_back(it.first);
        }
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());

        ll X1 = LLONG_MIN;
        for(int i=0;i<n;++i) X1 = max(X1, A[i]-C);
        vector<ll> candX = {L,R,X1};

        ll best = LLONG_MAX;
        int movePtr = ptr;

        for(ll X: candX){
            fCountA = SegTree(coordsA.size());
            fSumA = SegTree(coordsA.size());
            fCountB = SegTree(coordsB.size());
            fSumB = SegTree(coordsB.size());

            int ptr2 = 0;
            for(; ptr2 < n && items[ptr2].first <= L; ++ptr2){
                int ia = idxA(items[ptr2].second.first);
                fCountA.add(ia,1);
                fSumA.add(ia, items[ptr2].second.first);
            }
            for(int i=ptr2;i<n;++i){
                int ib = idxB(items[i].second.second);
                fCountB.add(ib,1);
                fSumB.add(ib, items[i].second.second);
            }

            int movePtr2 = ptr2;

            for(ll delta: cand){
                while(movePtr2 < n && items[movePtr2].first <= delta){
                    int ib = idxB(items[movePtr2].second.second);
                    fCountB.add(ib,-1);
                    fSumB.add(ib,-items[movePtr2].second.second);
                    int ia = idxA(items[movePtr2].second.first);
                    fCountA.add(ia,1);
                    fSumA.add(ia, items[movePtr2].second.first);
                    movePtr2++;
                }

                int idxLessA = upper_bound(coordsA.begin(), coordsA.end(), X-1) - coordsA.begin();
                ll cntA_lt = fCountA.sumPrefix(idxLessA);
                ll sumA_lt = fSumA.sumPrefix(idxLessA);
                ll contribA = cntA_lt*X - sumA_lt;

                ll thrB = X - delta;
                int idxLessB = upper_bound(coordsB.begin(), coordsB.end(), thrB-1) - coordsB.begin();
                ll cntB_lt = fCountB.sumPrefix(idxLessB);
                ll sumB_lt = fSumB.sumPrefix(idxLessB);
                ll contribB = cntB_lt*(X-delta) - sumB_lt;

                ll total = contribA + contribB;
                best = min(best, total);
            }
        }

        if(best == LLONG_MAX) cout << -1 << '\n';
        else cout << best << '\n';
    }
    return 0;
}

