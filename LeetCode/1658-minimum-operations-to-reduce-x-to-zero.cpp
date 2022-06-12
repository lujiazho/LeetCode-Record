///////////////////////////////////////////////////////////////////////////////////////////////
// complex edge cases
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum_middle = accumulate(nums.begin(), nums.end(), 0) - x;
        if (sum_middle < 0) return -1;
        int i=0, j=0;
        int cur_sum = 0;
        int max_w = -1;
        while (j < nums.size()){
            cur_sum += nums[j];
            if (cur_sum < sum_middle){
                j ++;
            }else if (cur_sum == sum_middle){
                max_w = max(max_w, j-i+1);
                j ++;
            }else{
                while (i <= j && cur_sum > sum_middle){
                    cur_sum -= nums[i];
                    i ++;
                }
                if (cur_sum == sum_middle)
                    max_w = max(max_w, j-i+1);
                j ++;
            }
        }
        return max_w==-1?-1:nums.size() - max_w;
    }
};
