class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> st;
        if(score.empty()){
            return st;
        }
        priority_queue<int>pq;
        for(int i : score){
            pq.push(i);
        }
        int count = 1;
        unordered_map<int, int>mp;
        while(!pq.empty()){
            mp[pq.top()] = count;
            pq.pop();
            count++;
        }
        for(int i = 0; i<score.size(); i++){
            if(mp[score[i]] == 1){
                st.push_back("Gold Medal");
                continue;
            }
            if(mp[score[i]] == 2){
                st.push_back("Silver Medal");
                continue;
            }
            if(mp[score[i]] == 3){
                st.push_back("Bronze Medal");
                continue;
            }
            st.push_back(to_string(mp[score[i]]));
        }
        return st;
    }
};