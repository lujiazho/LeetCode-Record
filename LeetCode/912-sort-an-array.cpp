///////////////////////////////////////////////////////////////////////////////////////////////
// basic
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;

        int pick=nums[(l+r)>>1], i=l-1, j=r+1, ex;
        while (i < j) {
            i ++;
            while (nums[i] < pick) i++;
            j --;
            while (nums[j] > pick) j--;
            
            if (i < j) {
                ex = nums[i];
                nums[i] = nums[j];
                nums[j] = ex;
            }
        }
        quickSort(nums, l, j);
        quickSort(nums, j+1, r);
    }
};