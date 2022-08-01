///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

// use heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> heap(nums.begin(), nums.end());
        for (int i=heap.size()/2-1 ; i>=0 ; i--) down(heap, i);
        int val;
        while (k--){
            val = heap[0];
            heap[0] = heap.back();
            heap.pop_back();
            down(heap, 0);
        }
        return val;
    }
    void down(vector<int>& heap, int idx){
        int t = idx, size = heap.size();
        if (idx*2+1 < size && heap[idx*2+1] > heap[t])
            t = idx*2+1;
        if (idx*2+2 < size && heap[idx*2+2] > heap[t])
            t = idx*2+2;
        if (t != idx){
            int tmp = heap[idx];
            heap[idx] = heap[t];
            heap[t] = tmp;
            down(heap, t);
        }
    }
};
