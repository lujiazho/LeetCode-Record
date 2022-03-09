///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode* i = head;
        unordered_set<int> s;
        while (i){
            if (i->next && i->next->val == i->val){
                i->next = i->next->next;
                s.insert(i->val);
            }
            i = i->next;
        }
        i = head;
        while (i->next){
            if (s.find(i->next->val) != s.end()) i->next = i->next->next;
            else i = i->next;
        }
        if (s.find(head->val) != s.end()) return head->next;
        return head;
    }
};