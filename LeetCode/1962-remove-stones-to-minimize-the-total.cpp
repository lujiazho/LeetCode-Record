///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // big in first at default
        priority_queue<int> heap;
        for(auto p : piles) heap.push(p);

        while(k--) {
            int num = heap.top();
            heap.pop();
            heap.push(num - num / 2);
        }

        int res = 0;
        while(heap.size()) {
            res += heap.top();
            heap.pop();
        }
        return res;
    }
};