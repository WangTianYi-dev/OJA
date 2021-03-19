#include <iostream>
#include <string>
using namespace std;
class Trie {
public:
    Trie* next[26] = { nullptr };
    bool end = false;

    /** Initialize your data structure here. */
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* p = this;
        for (const auto& i : word) {
            if (p->next[i - 'a']) {
                p = p->next[i - 'a'];
            } else {
                p = p->next[i - 'a'] = new Trie();
            }
        }
        p->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie* p = this;
        for (const auto& i : word) {
            if (p->next[i - 'a']) {
                p = p->next[i - 'a'];
            } else {
                return false;
            }
        }
        return p->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie* p = this;
        for (const auto& i : prefix) {
            if (p->next[i - 'a']) {
                p = p->next[i - 'a'];
            } else {
                return false;
            }
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

int main()
{
    // Trie* o = new Trie();
    // o->insert("apple");
    // cout << o->search("apple");
    // memset(
    // return 0;
}