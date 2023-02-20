///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1, mid;
        while (i < j) {
            mid = (i+j)>>1;
            if (nums[mid] < target) i = mid+1;
            else j = mid;
        }
        return nums[i]>=target?i:i+1;
    }
};