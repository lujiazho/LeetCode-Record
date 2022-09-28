///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, just need to have a clear thought about the process of algo
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = NULL, *i = head;
        int idx = 1;
        while (i->next) {
            if (idx >= n) {
                if (!p) p = head;
                else p = p->next;
            }
            i = i->next;
            idx += 1;
        }
        if (p) p->next = p->next->next;
        else return head->next;
        return head;
    }
};