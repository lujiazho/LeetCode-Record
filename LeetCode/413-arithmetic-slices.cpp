///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int first_idx = 0;
        int diff = nums[1] - nums[0];
        int last = nums[1];
        int res = 0;
        for (int i=2 ; i<nums.size() ; i++){
            if (nums[i] - last == diff){
                last = nums[i];
            }else{
                int len_ = i - first_idx;
                res += (1+(len_-2))*(len_-2)/2;
                first_idx = i-1;
                diff = nums[i] - last;
                last = nums[i];
            }
        }
        int len_ = nums.size() - first_idx;
        res += (1+(len_-2))*(len_-2)/2;
        return res;
    }
};