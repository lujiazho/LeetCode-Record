///////////////////////////////////////////////////////////////////////////////////////////////
// use sort to reduce one loop
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n-2; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                if (abs(ans - target) > abs(sum3 - target)) ans = sum3;
                
                // already got best
                if (sum3 == target) break;
                // move to be close to target
                if (sum3 > target) r--;
                else l++;
            }
        }
        return ans;
    }
};
