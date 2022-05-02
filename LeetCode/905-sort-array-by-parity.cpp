///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=-1,j=nums.size();
        while (i < j){
            i++;
            while (i<j && nums[i] % 2 == 0)
                i++;
            j--;
            while (i<j && nums[j] % 2)
                j--;
            if (i < j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return nums;
    }
};