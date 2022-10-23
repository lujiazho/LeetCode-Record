///////////////////////////////////////////////////////////////////////////////////////////////
// brilliant solution of others
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // shift all to should-be place
        for(int i = 0; i<nums.size(); i++){
            while(nums[i] != nums[nums[i] - 1]) 
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i] != i + 1)
                return {nums[i], i + 1};
        }
        return {-1, -1};
    }
};