class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }

    int query(int l, int r) {
        if (l > r)
            return 0;
        return query(1, 0, n, l, r);
    }
};


class Solution {

public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;
        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }
        SegmentTree seg(MAXX);
        auto it = obstacles.begin();
        auto prevIt = it;
        ++it;
        for (; it != obstacles.end(); ++it) {
            seg.update(*it, *it - *prevIt);
            prevIt = it;
        }
        vector<bool> ans;
        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            auto &q = queries[i];
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];
                int best = seg.query(0, x);
                auto itObs = obstacles.upper_bound(x);
                --itObs;
                best = max(best, x - *itObs);
                ans.push_back(best >= sz);
            }
            else {
                int x = q[1];
                auto cur = obstacles.find(x);
                auto leftIt = std::prev(cur);
                auto rightIt = std::next(cur);
                int L = *leftIt;
                int R = *rightIt;
                seg.update(x, 0);
                seg.update(R, R - L);
                obstacles.erase(cur);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};