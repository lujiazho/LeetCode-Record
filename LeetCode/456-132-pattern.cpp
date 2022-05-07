///////////////////////////////////////////////////////////////////////////////////////////////
// very tricky
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        vector<int> left_min;
        left_min.push_back(nums[0]);
        for (int i=1; i < nums.size(); i++)
            left_min.push_back(min(nums[i], left_min[i-1]));
        // Monotonic stack: big to small
        vector<int> mono;
        for (int i=nums.size()-1 ; i>=0 ; i--){
            while (mono.size() && mono.back() <= left_min[i])
                mono.pop_back();
            if (mono.size() && mono.back() < nums[i])
                return true;
            mono.push_back(nums[i]);
        }
        return false;
    }
};