///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2){
            if (!list1) return list2;
            return list1;
        }
        ListNode* res = new ListNode();
        ListNode* node = res;
        while (list1 && list2){
            if (list1->val <= list2->val){
                node->next = list1;
                list1 = list1->next;
            }else{
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }
        if (list1) node->next = list1;
        if (list2) node->next = list2;
        return res->next;
    }
};