struct TrieNode {
    TrieNode* next[26] = {0};
    bool leaf = 0;
    TrieNode(bool b) : leaf(b) {}
};

class Trie {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(0);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!cur->next[word[i] - 'a']) {
                cur->next[word[i] - 'a'] = new TrieNode(0);
            }
            cur = cur->next[word[i] - 'a'];
        }
        cur->leaf = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (int i = 0; i < word.length(); ++i) {
            if (!cur->next[word[i] - 'a']) {
                return 0;
            }
            cur = cur->next[word[i] - 'a'];
        }
        return cur->leaf ? 1 : 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.length(); ++i) {
            if (!cur->next[prefix[i] - 'a']) {
                return 0;
            }
            cur = cur->next[prefix[i] - 'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */