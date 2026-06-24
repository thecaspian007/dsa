class Solution {
public:
    string reorganizeString(string s) {
      vector<int> freq(26, 0);

        int maxFreq = 0;

        for(char ch : s) {
            freq[ch - 'a']++;
            maxFreq = max(maxFreq, freq[ch - 'a']);
        }

        int n = s.size();

        if(maxFreq > (n + 1) / 2)
            return "";

        priority_queue<pair<int,char>> pq;

        for(int i = 0; i < 26; i++) {
            if(freq[i]) {
                pq.push({freq[i], char('a' + i)});
            }
        }

        string ans;

        pair<int,char> prev = {0, '#'}; // held-out char

        while(!pq.empty()) {

            auto [cnt, ch] = pq.top();
            pq.pop();

            ans.push_back(ch);
            cnt--;

            if(prev.first > 0) {
                pq.push(prev);
            }
            prev = {cnt, ch};
        }
        return ans;  
    }
};