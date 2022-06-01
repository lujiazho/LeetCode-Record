///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> s;
        s.push_back(nums[0]);
        for (int i=1 ; i<nums.size() ; i++){
            s.push_back(s.back()+nums[i]);
        }
        return s;
    }
};