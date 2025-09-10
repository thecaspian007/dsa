class Solution {
public:
    bool intersection(unordered_set<int>& X, unordered_set<int>& Y){
        if (X.size()>Y.size()) return intersection(Y, X);
        for(int x: X){
            if (Y.count(x)) return 1;
        }
        return 0;
    } 
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
       int m=languages.size(); 
        vector<unordered_set<int>> know(m);
        for (int i=0; i<m; i++) 
            for (int l : languages[i]) know[i].insert(l);
        unordered_set<int> need;
        need.reserve(500);
        for (auto& f : friendships) {
            int a=f[0]-1, b=f[1]-1;
            if (intersection(know[a],know[b])) continue; 
            need.insert(a);
            need.insert(b);
        }
        if (need.size()==0) return 0;
        int ans=INT_MAX;
        for (int lang=1; lang<=n; lang++) {   
            int cnt=0;
            for (int i: need) {
                if (!know[i].count(lang)) cnt++;
            }
            ans=min(ans, cnt);
        }
        return ans; 
    }
};