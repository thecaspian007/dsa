class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string>ans;
        if(len == 0)
        {
            return ans;
        }
        if(len == 1)
        {
             ans.push_back(to_string(nums[0]));
             return ans;
        }

        string t;
        vector<long long int>val;

        for(int i = 0; i<len; i++)
        {
            if(i != len-1 && static_cast<long long>(nums[i+1]) - static_cast<long long>(nums[i]) == 1)
            {
                val.push_back(nums[i]);

            }
            else
            {
                if(val.size() == 0)
                {
                    ans.push_back(to_string(nums[i]));
                }
                else
                {
                    val.push_back(nums[i]);
                    int len = val.size();
                    t = t + to_string(val[0]);
                    t = t + "->";
                    t = t + to_string(val[len-1]);
                    ans.push_back(t);
                    t = "";
                    val.clear();

                }
            }
        }
        return ans;
    }
};