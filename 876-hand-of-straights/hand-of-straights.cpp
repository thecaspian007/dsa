class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for (int card : hand)
            freq[card]++;
        for (int card : hand) {
            // Already used
            if (freq[card] == 0)
                continue;
            // Try to build one group
            for (int i = 0; i < groupSize; i++) {
                int curr = card + i;
                if (freq[curr] == 0)
                    return false;
                freq[curr]--;
            }
        }
        return true;
    }
};