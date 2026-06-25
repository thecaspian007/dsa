class Solution {
public:
    class Fenwick {
        vector<int> bit;
        int n;

    public:
        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }

        long long sum(int idx) {
            long long res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }
        vector<int> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        Fenwick bit(vals.size());
        long long ans = 0;
        for (int x : pref) {
            int pos = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;
            ans += bit.sum(pos - 1);
            bit.add(pos, 1);
        }
        return ans;
    }
};