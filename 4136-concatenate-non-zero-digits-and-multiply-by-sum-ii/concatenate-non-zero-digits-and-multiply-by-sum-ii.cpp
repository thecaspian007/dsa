class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> pos;
        vector<int> digit;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i] - '0');
            }
        }
        int m = digit.size();
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }
        vector<long long> prefNumber(m);
        for (int i = 0; i < m; i++) {
            if (i == 0)
                prefNumber[i] = digit[i];
            else
                prefNumber[i] = (prefNumber[i - 1] * 10 + digit[i]) % MOD;
        }
        vector<long long> prefSum(m);
        for (int i = 0; i < m; i++) {
            if (i == 0)
                prefSum[i] = digit[i];
            else
                prefSum[i] = prefSum[i - 1] + digit[i];
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin() - 1;
            if (L > R) {
                ans.push_back(0);
                continue;
            }
            int len = R - L + 1;
            long long x;
            if (L == 0) {
                x = prefNumber[R];
            } else {
                x = (prefNumber[R] -
                     prefNumber[L - 1] * pow10[len] % MOD +
                     MOD) % MOD;
            }
            long long sum = prefSum[R];
            if (L > 0)
                sum -= prefSum[L - 1];
            ans.push_back((x * sum) % MOD);
        }
        return ans;
    }
};