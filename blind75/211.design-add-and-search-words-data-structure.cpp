/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary
{
public:
    struct TrieNode
    {
        TrieNode *ch[26];
        bool word;
    };

    TrieNode *root;

    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        TrieNode *p = root;
        for (char c : word)
        {
            if (!p->ch[c - 'a'])
                p->ch[c - 'a'] = new TrieNode();
            p = p->ch[c - 'a'];
        }
        p->word = true;
    }

    bool searchword(string &word, TrieNode *p, int i)
    {
        if (word.size() == i)
            return p->word;
        if (word[i] == '.')
        {
            for (auto &a : p->ch)
            {
                if (a && searchword(word, a, i + 1))
                    return true;
            }
            return false;
        }
        return p->ch[word[i] - 'a'] && searchword(word, p->ch[word[i] - 'a'], i + 1);
    }

    bool search(string word)
    {
        TrieNode *p = root;
        return searchword(word, p, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
