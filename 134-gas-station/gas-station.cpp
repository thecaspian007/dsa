class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i=0;i<gas.size();i++)
        {
            cost[i]=gas[i]-cost[i];
        }
        int res=0;
        for(int i=0;i<cost.size();i++)
        {
            res+=cost[i];
        }
        if(res<0)
            return -1;
        res=0;
        int idx=0;
        for(int i=0;i<cost.size();i++)
        {
            res+=cost[i];
            if(res<0)
            {
                idx=i+1;
                res=0;
            }
        }
        return idx;
    }
};