class Solution {
public:
    bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left++] != s[right--])
            return false;
    }
    return true;
    }

    string toBaseK(long long num, int k) {
    string res;
    while (num > 0) {
        res = char('0' + num % k) + res;
        num /= k;
    }
    return res;
    }

    vector<long long> generatePalindromes(int length) {
    vector<long long> res;

    // Even length: mirror "123" → "123321"
    for (int half = pow(10, (length - 1) / 2); half < pow(10, (length + 1) / 2); ++half) {
        string s = to_string(half);
        string rev = s;
        reverse(rev.begin(), rev.end());

        string full = (length % 2 == 0) ? s + rev : s + rev.substr(1);
        res.push_back(stoll(full));
    }

    return res;
    }

    long long kMirror(int k, int n) {
    int length = 1;
    int count = 0;
    long long sum = 0;

    while (count < n) {
        vector<long long> pals = generatePalindromes(length);
        for (long long num : pals) {
            string baseK = toBaseK(num, k);
            if (isPalindrome(baseK)) {
                sum += num;
                count++;
                if (count == n)
                    return sum;
            }
        }
        length++;
    }

    return sum;
    }
};