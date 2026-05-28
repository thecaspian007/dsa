class Solution {
public:

    struct TrieNode {

        int child[26];
        int bestIndex;

        TrieNode() {

            memset(child, -1, sizeof(child));

            bestIndex = -1;
        }
    };

    vector<TrieNode> trie;
    vector<string>* wordsPtr;

    bool better(int idx1, int idx2) {

        if (idx2 == -1)
            return true;

        auto &words = *wordsPtr;

        if (words[idx1].size() < words[idx2].size())
            return true;

        if (words[idx1].size() == words[idx2].size()
            && idx1 < idx2)
            return true;

        return false;
    }

    void insert(string &word, int index) {

        int node = 0;

        if (better(index, trie[node].bestIndex)) {
            trie[node].bestIndex = index;
        }

        // traverse from back
        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {

                trie[node].child[c] = trie.size();

                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            if (better(index, trie[node].bestIndex)) {
                trie[node].bestIndex = index;
            }
        }
    }

    int query(string &word) {

        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                break;
            }

            node = trie[node].child[c];
        }

        return trie[node].bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        wordsPtr = &wordsContainer;

        trie.reserve(500000 + 5);

        trie.push_back(TrieNode());
        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }
        vector<int> ans;
        for (auto &q : wordsQuery) {
            ans.push_back(query(q));
        }
        return ans;
    }
};