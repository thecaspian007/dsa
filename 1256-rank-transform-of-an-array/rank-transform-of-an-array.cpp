class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        if(arr.empty()){
            return ans;
        }
        priority_queue<int, vector<int>, greater<int>>pq;
        for (int el : arr){
            pq.push(el);
        }
        unordered_map<int, int>mp;
        int counter = 1;
        while(!pq.empty()){
          mp[pq.top()] = counter;
          pq.pop();
          if(!pq.empty() && mp.find(pq.top()) != mp.end()){
            continue;
          }
          counter++;
        }
        for(int el : arr){
            if(mp.find(el) != mp.end()){
                ans.push_back(mp[el]);
            }
        }
        return ans;
    }
};