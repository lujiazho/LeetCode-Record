///////////////////////////////////////////////////////////////////////////////////////////////
// this is called RESERVOIR SAMPLING, the math behind it is interesting
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    ListNode* h;
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        int val = h->val;
        int i = 2;
        ListNode* next = h->next;
        while(next){
            // we can calculate that the probability for each number is equal
            if (rand()*1.0 / RAND_MAX < 1.0/i) val = next->val;
            i += 1;
            next = next->next;
        }
        return val;
    }
};
