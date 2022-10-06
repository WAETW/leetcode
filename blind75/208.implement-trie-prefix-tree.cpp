/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
    struct TrieNode {
        bool word;
        TrieNode* ch[26];
    };

   public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (!p->ch[c - 'a']) {
                p->ch[c - 'a'] = new TrieNode();
            }
            p = p->ch[c - 'a'];
        }
        p->word = true;
    }

    bool search(string word) {
        TrieNode* p = root;
        for (char c : word) {
            if (!p->ch[c - 'a'])
                return false;
            p = p->ch[c - 'a'];
        }
        return p->word;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (char c : prefix) {
            if (!p->ch[c - 'a'])
                return false;
            p = p->ch[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
