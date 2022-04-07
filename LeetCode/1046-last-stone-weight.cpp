///////////////////////////////////////////////////////////////////////////////////////////////
// greedy method
////////////////
// Time Complexity: O(nlogn), mainly on sorting
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> heap(stones.begin(), stones.end());
        int x, y;
        while (heap.size() > 1){
            x = heap.top();
            heap.pop();
            y = heap.top();
            heap.pop();
            if (x != y)
                heap.push(abs(x-y));
        }
        return heap.size()?heap.top():0;
    }
};