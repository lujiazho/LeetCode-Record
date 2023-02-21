///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0, j=nums.size()-1, mid;
        while (i < j) {
            mid = (i+j) >> 1;
            if (mid % 2 == 1) mid--; // make it to be at odd position

            if (nums[mid] == nums[mid+1]) i = mid+2;
            else j = mid;
        }
        return nums[i];
    }
};