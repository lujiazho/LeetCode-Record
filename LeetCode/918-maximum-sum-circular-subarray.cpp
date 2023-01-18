///////////////////////////////////////////////////////////////////////////////////////////////
// good solution from others
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total_sum=0, curr_sum1=0, curr_sum2=0, mxsum_subary=INT_MIN, minsum_subary=INT_MAX;   
        for(auto i:nums) {
            total_sum += i; 
            curr_sum1 += i; 
            curr_sum2 += i;

            // find continuous max subarray
            mxsum_subary = max(mxsum_subary, curr_sum1);
            if(curr_sum1 < 0) curr_sum1 = 0;

            // find continuous min subarray
            minsum_subary = min(curr_sum2, minsum_subary);
            if(curr_sum2 > 0) curr_sum2 = 0;
        }
        // if total_sum==minsum_subary 
        //    means all elements are negative, then return the max one
        // else
        //    the maximum sum could be continuous (mxsum_subary) or at left and right (total_sum-minsum_subary)
        return (total_sum==minsum_subary) ? mxsum_subary : max(mxsum_subary, total_sum-minsum_subary);  
    }
};