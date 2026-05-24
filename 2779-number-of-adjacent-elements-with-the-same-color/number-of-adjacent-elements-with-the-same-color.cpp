class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>colors(n, 0);
        vector<int>ans;
        int adjacent = 0;

        for(auto &q : queries){
            int idx = q[0];
            int color = q[1];

            if(colors[idx] !=0) {
                if(idx>0 && colors[idx] == colors[idx-1]){
                    adjacent--;
                }

                if(idx<n-1 && colors[idx] == colors[idx+1]){
                    adjacent--;
                }
            }
            colors[idx] = color;
            if(idx>0 && colors[idx] == colors[idx-1]){
                adjacent++;
            }

            if(idx<n-1 && colors[idx] == colors[idx+1]){
                adjacent++;
            }
            ans.push_back(adjacent);
        }
        return ans;
    }
};