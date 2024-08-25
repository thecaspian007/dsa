class Solution {
public:
    bool isPalindrome(int x) {
        if(x>= 0 && x<10)
        {
            return true;
        }
        // else if()

        if(x<0)
        {
            return false;
        }

        vector<int>val;

        while(x>=1)
        {
            val.push_back(x%10);
            x = x/10;
        }  

        for(int i = 0; i<val.size()/2; i++)
        {
            if(val[i] != val[val.size()-i-1])
            {
                return false;
            }
        }

        return true;
    }
};