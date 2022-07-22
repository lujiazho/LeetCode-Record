///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        vector<ListNode*> less;
        vector<ListNode*> greater;
        while (head){
            if (head->val < x) less.push_back(head);
            else greater.push_back(head);
            head = head->next;
        }
        ListNode* res = new ListNode(0, NULL);
        ListNode* idx = res;
        for (int i=0 ; i<less.size() ; i++){
            idx->next = less[i];
            idx = idx->next;
        }
        for (int i=0 ; i<greater.size() ; i++){
            idx->next = greater[i];
            idx = idx->next;
        }
        idx->next = NULL;
        return res->next;
    }
};