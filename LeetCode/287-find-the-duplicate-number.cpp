///////////////////////////////////////////////////////////////////////////////////////////////
// changing the sign to label an accessed number is a really useful method
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[abs(nums[i])] > 0)
                nums[abs(nums[i])] *= -1;
            else
                return abs(nums[i]);
        }
        return -1;
    }
};