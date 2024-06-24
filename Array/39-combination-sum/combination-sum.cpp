class Solution {
public:
    void helper(int start, int target, vector<vector<int>> &ans,  vector<int> &temp, vector<int>& candidates)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }

        if(start ==  candidates.size() || target < 0)
        {
            return;
        }

        temp.push_back(candidates[start]);
        helper(start, target - candidates[start], ans, temp, candidates);
        temp.pop_back();

        while (start + 1 < candidates.size() && candidates[start] == candidates[start + 1])      
        {
            start++;
        }

           helper(start+1, target, ans, temp, candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       int len = candidates.size();
       vector<vector<int>> ans;
       vector<int>temp;

       if(len == 0)
       {
        return ans;
       }

       helper(0, target, ans, temp, candidates);
       return ans;
    }
};