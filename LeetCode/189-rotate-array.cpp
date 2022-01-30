///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res;
        if (k > nums.size())
            k %= nums.size();
        for (int i=nums.size()-k ; i<nums.size() ; i++)
            res.push_back(nums[i]);
        for (int i=0 ; i<nums.size()-k ; i++)
            res.push_back(nums[i]);
        for (int i=0 ; i<nums.size() ; i++)
            nums[i] = res[i];
    }
};