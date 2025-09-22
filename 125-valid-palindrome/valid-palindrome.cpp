class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
       if(len == 0)
       {
        return false;
       }
        string t;
       for(int i = 0; i< len; i++)
       {
        char a = s[i];
        if(a >= 'A' && a<= 'Z')
        {
            t.push_back(a-'A'+'a');
        }
        else if(a >= 'a' && a<= 'z')
        {
            t.push_back(a);
        }
        else if(a >= '0' && a<= '9')
        {
            t.push_back(a);
        }
       }
        int n = t.length();
       for(int i = 0; i<n/2; i++)
       {
        if(t[i] != t[n-i-1])
        {
            return false;
        }
       }
       return true;
    }
};