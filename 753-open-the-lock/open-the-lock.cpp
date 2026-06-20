class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000"))
            return -1;
        if(target == "0000")
            return 0;
        queue<pair<string,int>> q;
        unordered_set<string> vis;
        q.push({"0000", 0});
        vis.insert("0000");
        while(!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();
            if(cur == target)
                return steps;
            for(int i=0;i<4;i++) {
                string up = cur;
                string down = cur;
                up[i] = ((cur[i]-'0'+1)%10)+'0';
                down[i] = ((cur[i]-'0'+9)%10)+'0';
                if(!dead.count(up) && !vis.count(up)) {
                    vis.insert(up);
                    q.push({up, steps+1});
                }
                if(!dead.count(down) && !vis.count(down)) {
                    vis.insert(down);
                    q.push({down, steps+1});
                }
            }
        }
        return -1;
    }
};