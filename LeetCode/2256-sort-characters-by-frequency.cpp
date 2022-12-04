///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long totalsum = 0, currentsum = 0;
        int n = nums.size();
        
        for(auto i : nums) totalsum += i;
        
        int mini = INT_MAX;
        int idx = 0;
        
        for (int i=0; i<n; i++) {
            currentsum += nums[i];
            
            int avg1 = currentsum/(i+1);
            if(i == n-1) return avg1<mini?n-1:idx;
            
            int avg2 = (totalsum - currentsum)/(n-i-1);
            
            if (abs(avg1 - avg2) < mini) {
                mini = abs(avg1 - avg2);
                idx = i;
            }
        }
        
        return idx;
    }
};