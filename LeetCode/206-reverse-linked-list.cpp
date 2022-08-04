///////////////////////////////////////////////////////////////////////////////////////////////
// much clear thinking
////////////////
// Time Complexity: O(n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tmp = reverseList(head->next);
        ListNode* idx = tmp;
        while (idx->next) idx = idx->next;
        idx->next = head;
        head->next = NULL;
        return tmp;
    }
};