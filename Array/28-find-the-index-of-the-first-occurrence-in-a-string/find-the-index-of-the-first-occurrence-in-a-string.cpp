class Solution {
public:
    int strStr(string haystack, string needle) {
         int k=needle.size();
        if(haystack.size()<needle.size()) return -1;
        if(haystack.size()==needle.size()){
            if(haystack==needle) return 0;
            else return -1;
        }
        string str="";
        str=haystack.substr(0,k);
        int l=0;
        while((l+k)<=haystack.size()){
            str=haystack.substr(l,k);
            if(str==needle){
                return l;
            }
            l++;
        }
        return -1;
    }
};