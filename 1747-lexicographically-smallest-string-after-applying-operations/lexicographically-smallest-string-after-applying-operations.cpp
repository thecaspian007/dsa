class Solution {
public:
string rotateString(const string &s, int n) {
    int m = s.size();
    n %= m;
    return s.substr(m - n) + s.substr(0, m - n);
}

string addString(string s, int n) {
    for (int i = 1; i < s.size(); i += 2) {
        int x = (s[i] - '0' + n) % 10;
        s[i] = '0' + x;
    }
    return s;
}

string minString(const string &a, const string &b) {
    return (a < b) ? a : b;
}

string findLexSmallestString(string s, int a, int b) {
    queue<string> q;
    unordered_set<string> seen;
    q.push(s);
    seen.insert(s);
    string res = s;
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        string t1 = addString(curr, a);
        if (!seen.count(t1)) {
            res = minString(res, t1);
            seen.insert(t1);
            q.push(t1);
        }
        string t2 = rotateString(curr, b);
        if (!seen.count(t2)) {
            res = minString(res, t2);
            seen.insert(t2);
            q.push(t2);
        }
    }
    return res;
}
};