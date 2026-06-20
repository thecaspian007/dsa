class Solution {
public:
    string capitalizeTitle(string title) {
        for(char &ch : title)
            ch = tolower(ch);
        int n = title.size();
        int i = 0;
        while(i < n)
        {
            int start = i;
            while(i < n && title[i] != ' ')
                i++;
            int len = i - start;
            if(len > 2) title[start] = toupper(title[start]);
            i++; 
        }
        return title;
    }
};