///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        ListNode* i = head;
        while (i != NULL){
            auto get = s.find(i);
            if (get != s.end())
                return i;
            s.insert(i);
            i = i->next;
        }
        return NULL;
    }
};