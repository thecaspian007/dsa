class Solution {
public:
    class Fenwick {
public:
    vector<int> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int val = (nums[i] == target) ? 1 : -1;
            prefix[i + 1] = prefix[i] + val;
        }
        vector<int> comp = prefix;
        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());
        Fenwick bit(comp.size());
        long long ans = 0;
        for (int x : prefix) {
            int idx = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
            ans += bit.query(idx - 1);
            bit.update(idx, 1);
        }
        return ans;
    }
};