struct TrieNode {
    TrieNode* next[128] = {0};
    bool leaf;
    TrieNode(bool l = 0) : leaf(l) {}
};

class Solution {
    TrieNode* root;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int m = wordDict.size();
        root = new TrieNode();
        for (int i = 0; i < m; ++i) {
            TrieNode* cur = root;
            for (int j = 0; j < wordDict[i].length(); ++j) {
                if (!cur->next[wordDict[i][j]]) {
                    cur->next[wordDict[i][j]] = new TrieNode();
                }
                cur = cur->next[wordDict[i][j]];
            }
            cur->leaf = 1;
        }
        bool a[n + 1] = {0};
        a[0] = 1;
        for (int i = 0; i < n; ++i) {
            if (!a[i]) {
                continue;
            }
            TrieNode* cur = root;
            for (int j = i; j < n; ++j) {
                if (cur->next[s[j]]) {
                    cur = cur->next[s[j]];
                    if (cur->leaf) {
                        a[j + 1] = 1;
                    }
                    continue;
                }
                break;
            }
        }
        return a[n];
    }
};