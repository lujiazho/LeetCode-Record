///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1), do in-place
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int pre = RAND_MAX;
        int pre_num = 1;
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] != pre){
                pre = nums[i];
                pre_num = 1;
                if (k != i) nums[k] = nums[i];
                k += 1;
            }else if (pre_num < 2){
                pre_num += 1;
                if (k != i) nums[k] = nums[i];
                k += 1;
            }else pre_num += 1;
        }
        return k;
    }
};