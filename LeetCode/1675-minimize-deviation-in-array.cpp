///////////////////////////////////////////////////////////////////////////////////////////////
// this problem is really hard for me, because it's hard to think of making it all even at first
// then divide each of them until bump into odd, and most importantly: each step could generate min diff
// so we need to keep track of each step and the last condition
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> heap;
        int min_ = INT_MAX;
        // make all odd to even, and store in heap (top is the maximum because of minus sign)
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] % 2 == 1) nums[i] *= 2;
            heap.push(-nums[i]);
            min_ = min(nums[i], min_);
        }
        int res = INT_MAX;
        while (heap.top() % 2 == 0){
            // take the maximum number
            int k = heap.top();
            heap.pop();
            // update return val
            res = min(-k-min_, res); // each step may generate min diff
            // update new min
            min_ = min(min_, -k/2);
            // make it half
            heap.push(k/2);
        }
        return min(res, -heap.top()-min_); // last step could also generate min
    }
};
