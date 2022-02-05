///////////////////////////////////////////////////////////////////////////////////////////////
// utilize heap
////////////////
// Time Complexity: O(n), this is n because the number of all nodes won't exceed the max length of lists, which is n
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> heap;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i=0 ; i<lists.size() ; i++){
            ListNode* h = lists[i];
            while (h){
                heap.push(h->val);
                h = h->next;
            }
        }
        ListNode* res = new ListNode();
        ListNode* i = res;
        while (heap.size()){
            int val = heap.top();
            heap.pop();
            i->next = new ListNode(val);
            i = i->next;
        }
        return res->next;
    }
};