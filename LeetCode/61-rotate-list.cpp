///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but a little bit tedious
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) return head;
        ListNode* i = head;
        int n = 1;
        while (i->next){
            i = i->next;
            n++;
        }
        k %= n;
        if (!k) return head;
        ListNode* pre = new ListNode();
        pre->next = head;
        int idx = 0;
        i = pre;
        ListNode* res;
        while (i->next){
            i = i->next;
            idx += 1;
            if (idx == n-k){
                res = i->next;
                i->next = NULL;
                i = res;
                idx += 1;
            }
        }
        i->next = head;
        return res;
    }
};