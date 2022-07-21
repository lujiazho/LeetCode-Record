///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector<ListNode*> v;
        int idx = 1;
        ListNode* pointer = head;
        ListNode* front = NULL;
        ListNode* end = NULL;
        while (pointer){
            if (idx == left - 1) front = pointer;
            if (idx == right + 1) end = pointer;
            if (idx >= left && idx <= right) v.push_back(pointer);
            pointer = pointer->next;
            idx += 1;
        }
        
        for (int i=v.size()-1 ; i>0 ; i--) v[i]->next = v[i-1];
        
        if (front) front->next = v.back();
        else head = v.back();
        
        if (end) v[0]->next = end;
        else v[0]->next = NULL;
        
        return head;
    }
};