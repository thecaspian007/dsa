class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        if(k == 0){
            return 0;
        }
        int size = profits.size();
        vector<pair<int, int>> projects(size);
        for(int i = 0; i<size; i++){
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        priority_queue<int>maximise;
        int i = 0;
        while(k--){
            while(i<size && projects[i].first <=w){
                maximise.push(projects[i].second);
                i++;
            }
            if(maximise.empty()){
                break;
            }
            w += maximise.top();
            maximise.pop();
        }
        return w;
    }
};