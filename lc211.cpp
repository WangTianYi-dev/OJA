#include "leetcode.h"
struct Trie {
    Trie* next[26] = { nullptr };
    bool end = false;
    Trie() {};
    void insert(string& word)
    {
        Trie* p = this;
        for (auto i : word) {
            if (p->next[i - 'a']) {
                p = p->next[i - 'a'];
            } else {
                p = p->next[i - 'a'] = new Trie();
            }
        }
        p->end = true;
    }

    bool search(const string& word, int cur)
    {
        if (word.length() == cur) {
            return this->end;
        }
        char c = word[cur];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (this->next[i] && this->next[i]->search(word, cur + 1)) {
                    return true;
                }
            }
            return false;
        }
        if (this->next[c - 'a']) {
            return this->next[c - 'a']->search(word, cur + 1);
        }
        return false;
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root;
    WordDictionary()
    {
        root = new Trie();
    }

    void addWord(string word)
    {
        root->insert(word);
    }

    bool search(string word)
    {
        return root->search(word, 0);
    }
};

int main()
{
    // Your WordDictionary object will be instantiated and called as such:
    WordDictionary* obj = new WordDictionary();
    obj->addWord("add");
    bool param_2 = obj->search("add");
    cout << param_2 << endl;
    return 0;
}
