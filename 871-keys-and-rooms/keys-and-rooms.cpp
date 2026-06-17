class Solution {
public:
     void dfs(int room, vector<vector<int>>& rooms, vector<int>& vis)
    {
        vis[room] = 1;
        for(int nextRoom : rooms[room])
        {
            if(!vis[nextRoom])
            {
                dfs(nextRoom, rooms, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, 0);
        dfs(0, rooms, vis);
        for(int room = 0; room < n; room++)
        {
            if(!vis[room])
            {
                return false;
            }
        }
        return true;
    }
};