class Solution {
public:
    string nearestPalindromic(string n) {
          int len = n.length();
    long long num = stoll(n); // Convert string to long long

    if (num <= 10 || (num % 10 == 0 && num == pow(10, len - 1))) {
        return to_string(num - 1); // Single-digit or exact powers of 10
    }

    // Create vector of candidate palindromes
    vector<long long> candidates;
    candidates.push_back(pow(10, len - 1) - 1); // Smallest number with one less digit
    candidates.push_back(pow(10, len) + 1);     // Smallest number with one more digit

    // Create palindrome from the prefix
    long long prefix = stoll(n.substr(0, (len + 1) / 2));
    for (int i = -1; i <= 1; ++i) {
        string p = to_string(prefix + i);
        string candidate = p + string(p.rbegin() + (len % 2), p.rend());
        candidates.push_back(stoll(candidate));
    }

    // Find the closest palindrome
    long long closest = -1;
    for (long long cand : candidates) {
        if (cand != num) {  // Skip the number itself
            if (closest == -1 || abs(cand - num) < abs(closest - num) || 
                (abs(cand - num) == abs(closest - num) && cand < closest)) {
                closest = cand;
            }
        }
    }
    return to_string(closest); // Return the closest palindrome
    }
};