#include "leetcode.h"
// struct ListNode;

class Solution {
public:
    void rev(ListNode* & head, ListNode* & tail) {
        ListNode* prev = tail->next, *p = head, *nxt = nullptr;
        while (prev != tail) {
            nxt = p->next;
            p->next = prev;
            prev = p;
            p = nxt;
        }
        swap(head, tail);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair, *tail = pre, *nxt = nullptr;
        while (head) {
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            nxt = tail->next;
            rev(head, tail);
            pre->next = head;
            tail->next = nxt;
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};