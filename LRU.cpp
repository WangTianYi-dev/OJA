#include "leetcode.h"

struct node {
    node *next, *prev;
    int val;
    node(int v) : val(v), next(nullptr), prev(nullptr){};
};

class LRUCache {
  public:
    int c, size = 0;
    node *head = nullptr, *tail = nullptr;
    unordered_map<int, int> cache;
    void insert_next(node *prev, node *n) {
        n->prev = prev;
        n->next = prev->next;
        n->prev->next = n;
        n->next->prev = n;
    }

    void del(node *n) {
        if (n->next) {
            n->next->prev = n->prev;
        }
        if (n->prev) {
            n->prev->next = n->next;
        }
        delete n;
    }

    LRUCache(int capacity) {
        c = capacity;
        head = new node(0);
        tail = new node(0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
    }

    void over_flow() {
        int k = tail->prev->val;
        del(tail->prev);
        cache.erase(k);
        size--;
    }

    void put(int key, int value) {
        size++;
        cache[key] = value;
        if (size > c) {
            over_flow();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */