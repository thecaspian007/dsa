class Solution {
public:
    static const long long LIMIT = 1000000;

    long long comb(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
    for (int x : cnt)
        total += x;

    long long ans = 1;
    int remaining = total;

    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0)
            continue;

        ans *= comb(remaining, cnt[i]);

        if (ans >= LIMIT)
            return LIMIT;

        remaining -= cnt[i];
    }
    return min(ans, LIMIT);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        vector<int> half(26);
        string mid = "";
        int len = 0;
        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            len += half[i];
            if (freq[i] % 2)
                mid = char('a' + i);
        }
        string first = "";
        while ((int)first.size() < len) {
            bool found = false;
            for (int c = 0; c < 26; c++) {
                if (half[c] == 0)
                    continue;
                half[c]--;
                long long ways = countWays(half);
                if (ways >= k) {
                    first += char('a' + c);
                    found = true;
                    break;
                }
                k -= ways;
                half[c]++;
            }
            if (!found)
                return "";
        }
        string second = first;
        reverse(second.begin(), second.end());
        return first + mid + second;
    }
};