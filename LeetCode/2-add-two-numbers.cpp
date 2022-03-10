///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but tedious
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode();
        ListNode* i = res;
        int c = 0;
        while (l1 && l2){
            int val = l1->val + l2->val + c;
            ListNode* nex = new ListNode(val%10);
            c = val/10;
            i->next = nex;
            i = i->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            int val = l1->val + c;
            ListNode* nex = new ListNode(val%10);
            c = val/10;
            i->next = nex;
            i = i->next;
            l1 = l1->next;
        }
        while (l2) {
            int val = l2->val + c;
            ListNode* nex = new ListNode(val%10);
            c = val/10;
            i->next = nex;
            i = i->next;
            l2 = l2->next;
        }
        if (c) {
            ListNode* nex = new ListNode(c);
            i->next = nex;
        }
        return res->next;
    }
};