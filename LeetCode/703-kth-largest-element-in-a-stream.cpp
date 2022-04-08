///////////////////////////////////////////////////////////////////////////////////////////////
// good method from others, we only store the fisrt k largest numbers
////////////////
// Time Complexity: O(logn), add function is O(logn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int i=0 ; i<nums.size() ; i++) {
            heap.push(nums[i]);
            if (heap.size() > K)
                heap.pop(); // ignore the number that is less than the kth largest
        }
    }
    
    int add(int val) {
        heap.push(val); // logn
        if (heap.size() > K)
            heap.pop();
        return heap.top();
    }
};