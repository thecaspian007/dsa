class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> freq;
        int left = 0;
        int distinct = 0;
        int ans = 0;
        for(int right = 0; right < fruits.size(); right++)
        {
            if(freq[fruits[right]] == 0)
                distinct++;
            freq[fruits[right]]++;
            while(distinct > 2)
            {
                freq[fruits[left]]--;
                if(freq[fruits[left]] == 0)
                {
                    distinct--;
                    freq.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};