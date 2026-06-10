class Solution {
public:
    vector<vector<int>> mxST, mnST;
    vector<int> lg;
    
    void buildSparse(vector<int>& nums) {
        int n = nums.size();

        lg.assign(n + 1, 0);
        for (int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        mxST.assign(K, vector<int>(n));
        mnST.assign(K, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mxST[0][i] = nums[i];
            mnST[0][i] = nums[i];
        }

        for (int k = 1; k < K; k++) {
            for (int i = 0;
                 i + (1 << k) <= n;
                 i++) {

                mxST[k][i] =
                    max(mxST[k - 1][i],
                        mxST[k - 1][i + (1 << (k - 1))]);

                mnST[k][i] =
                    min(mnST[k - 1][i],
                        mnST[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    long long maxTotalValue(vector<int>& nums, int k) {
         int n = nums.size();

        buildSparse(nums);

        auto getValue = [&](int l, int r) -> long long {
            int len = r - l + 1;
            int p = lg[len];

            int mx = max(mxST[p][l],
                         mxST[p][r - (1 << p) + 1]);

            int mn = min(mnST[p][l],
                         mnST[p][r - (1 << p) + 1]);

            return 1LL * mx - mn;
        };
        struct Node {
            long long val;
            int l;
            int r;

            bool operator<(const Node& other) const {
                return val < other.val;
            }
        };
        priority_queue<Node> pq;
        for (int l = 0; l < n; l++) {
            pq.push({getValue(l, n - 1), l, n - 1});
        }
        long long ans = 0;
        while (k--) {
            auto cur = pq.top();
            pq.pop();
            ans += cur.val;
            if (cur.r > cur.l) {
                pq.push({
                    getValue(cur.l, cur.r - 1),
                    cur.l,
                    cur.r - 1
                });
            }
        }
        return ans;  
    }
};