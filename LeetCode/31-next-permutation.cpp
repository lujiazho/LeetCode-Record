///////////////////////////////////////////////////////////////////////////////////////////////
// this is not easy, and I use the official c++ standard lib next_permutation method
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, ex;
        // find the last smaller number
        for (i=nums.size()-1 ; i>0 ; i--)
            if (nums[i] > nums[i-1]) break;
        // this means smaller one was found
        if (i > 0) {
            int j = nums.size() - 1;
            // find the last larger one
            while (j > i-1 && nums[j] <= nums[i-1])
                j--;
            // exchange them
            ex = nums[i-1];
            nums[i-1] = nums[j];
            nums[j] = ex;
        }
        // after i, they are descending now, changing them to ascending
        int st = i, ed = nums.size()-1;
        // reverse
        while (st < ed){
            ex = nums[st];
            nums[st++] = nums[ed];
            nums[ed--] = ex;
        }
    }
};