///////////////////////////////////////////////////////////////////////////////////////////////
// easy fast and slow
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast = head, *slow = head, *beforeslow = NULL;
        while (fast && fast->next) {
            beforeslow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!beforeslow) return NULL;
        beforeslow->next = slow->next;
        return head;
    }
};