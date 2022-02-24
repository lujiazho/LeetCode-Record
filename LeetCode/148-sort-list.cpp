///////////////////////////////////////////////////////////////////////////////////////////////
// very interesting, because this is my first to use merge sort on linked list
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* before_slow;
        while (fast != NULL && fast->next != NULL){
            before_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        before_slow->next = NULL;
        fast = sortList(slow); // part2
        slow = sortList(head); // part1
        return merge(slow, fast);
    }
    ListNode* merge(ListNode* n1, ListNode* n2){
        ListNode* ini = new ListNode(0);
        ListNode* res = ini;
        while (n1 && n2){
            if (n1->val < n2->val){
                ini->next = n1;
                n1 = n1->next;
            }else{
                ini->next = n2;
                n2 = n2->next;
            }
            ini = ini->next;
        }
        while (n1){
            ini->next = n1;
            ini = ini->next;
            n1 = n1->next;
        }
        while (n2){
            ini->next = n2;
            ini = ini->next;
            n2 = n2->next;
        }
        return res->next;
    }
};