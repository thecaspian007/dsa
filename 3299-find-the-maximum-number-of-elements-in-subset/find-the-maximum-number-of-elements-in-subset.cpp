class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int x : nums)
            freq[x]++;
        int ans = 1;
        if (freq.count(1)) {
            if (freq[1] % 2 == 0)
                ans = max(ans, freq[1] - 1);
            else
                ans = max(ans, freq[1]);
        }
        for (auto &[num, cnt] : freq) {
            if (num == 1)
                continue;
            long long cur = num;
            int len = 0;
            while (freq.count(cur)) {
                if (freq[cur] >= 2) {
                    len += 2;
                    cur = cur * cur;
                    if (cur > 1e18)
                        break;
                } else {
                    len += 1;
                    break;
                }
            }
            if (!freq.count(cur))
                len--;
            ans = max(ans, len);
        }
        return ans; 
    }
};