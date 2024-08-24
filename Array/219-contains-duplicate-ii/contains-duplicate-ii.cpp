class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        map<int, vector<int>>np;

        if(len == 0)
        {
            return false;
        }

        for(int i = 0; i<len; i++)
        {
            np[nums[i]].push_back(i);
        }

        for(auto a: np)
        {
             vector<int> val = a.second;
             int p = 0;
             if(val.size() >1)
             {
                for(int i = 1; i< val.size(); i++)
                {
                    if(abs(val[p] - val[i]) <= k )
                    {
                        return true;
                    }
                    else if(abs(val[p] - val[i]) > k )
                    {
                        p++;
                    }
                }
             }
        }
        return false;

    }
};