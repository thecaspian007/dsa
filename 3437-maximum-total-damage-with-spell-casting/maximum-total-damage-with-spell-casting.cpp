class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> damageFrequency;
        for (int damage : power) {
            damageFrequency[damage]++;
        }
        vector<int> uniqueDamages;
        for (const auto& pair : damageFrequency) {
            uniqueDamages.push_back(pair.first);
        }
        sort(uniqueDamages.begin(), uniqueDamages.end());
        int totalUniqueDamages = uniqueDamages.size();
        vector<long long> maxDamageDP(totalUniqueDamages, 0);
        maxDamageDP[0] = uniqueDamages[0] * damageFrequency[uniqueDamages[0]];
        for (int i = 1; i < totalUniqueDamages; i++) {
            int currentDamageValue = uniqueDamages[i];
            long long currentDamageTotal = currentDamageValue * damageFrequency[currentDamageValue];
            maxDamageDP[i] = maxDamageDP[i - 1];
            int previousIndex = i - 1;
            while (previousIndex >= 0 && 
                   (uniqueDamages[previousIndex] == currentDamageValue - 1 || 
                    uniqueDamages[previousIndex] == currentDamageValue - 2 || 
                    uniqueDamages[previousIndex] == currentDamageValue + 1 || 
                    uniqueDamages[previousIndex] == currentDamageValue + 2)) {
                previousIndex--;
            }
            if (previousIndex >= 0) {
                maxDamageDP[i] = max(maxDamageDP[i], maxDamageDP[previousIndex] + currentDamageTotal);
            } else {
                maxDamageDP[i] = max(maxDamageDP[i], currentDamageTotal);
            }
        }
        return maxDamageDP[totalUniqueDamages - 1];
    }
};