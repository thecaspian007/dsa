class Solution {
public:
    void backtracking(int i, int numLen, int curNum, unordered_map<int, int>& counter, vector<int>& out) {
        if (i == numLen) {
            bool isBalanceNumber = true;
            for (auto& [d, freq] : counter)
                if (freq > 0 && d != freq)
                    isBalanceNumber = false;
            if (isBalanceNumber) 
                out.push_back(curNum);
            return;
        }
        for (int d = 1; d <= numLen; ++d) {
            if (counter[d] >= d) continue; 
            if (counter[d] + (numLen - i) < d) continue;
            counter[d] += 1;
            backtracking(i + 1, numLen, curNum * 10 + d, counter, out);
            counter[d] -= 1;
        }
    }

    int nextBeautifulNumber(int n) {
        if (n == 0) return 1;
        int minNumLen = log10(n) + 1;
        for (int numLen = minNumLen; numLen <= minNumLen + 1; ++numLen) {
            vector<int> all;
            unordered_map<int, int> counter;
            backtracking(0, numLen, 0, counter, all);
            for (int num : all)
                if (num > n) return num;
        }
        return -1;
    }
};