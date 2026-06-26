class Solution {
public:
    class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    string search(string word) {
        TrieNode* node = root;
        string prefix;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->child[idx] == nullptr)
                return word;
            prefix += ch;
            node = node->child[idx];
            if (node->isEnd)
                return prefix;
        }
        return word;
    }
};
    string replaceWords(vector<string>& dictionary, string sentence) {
       Trie trie;

        for (string root : dictionary)
            trie.insert(root);

        stringstream ss(sentence);

        string word;
        string ans;
        while (ss >> word) {
            if (!ans.empty())
                ans += " ";
            ans += trie.search(word);
        }
        return ans; 
    }
};