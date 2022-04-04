///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* iter = head;
        int idx = 1;
        while (idx < k && iter->next){
            iter = iter->next;
            idx++;
        }
        ListNode* front = iter;
        ListNode* back = head;
        while (iter->next){
            iter = iter->next;
            back = back->next;
        }
        int val = front->val;
        front->val = back->val;
        back->val = val;
        return head;
    }
};