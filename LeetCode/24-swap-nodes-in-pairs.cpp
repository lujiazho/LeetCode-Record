///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *i = head, *j = head->next;
        i->next = j->next;
        j->next = i;
        head = j;
        while (i->next && i->next->next){
            j = i->next;
            i->next = j->next;
            j->next = j->next->next;
            i->next->next = j;
            ListNode* tmp = i;
            i = j;
            j = tmp;
        }
        return head;
    }
};

// above solution works well but a little bit messy, below recursion is brillant
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        return p;
    }
};
