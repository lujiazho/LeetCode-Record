///////////////////////////////////////////////////////////////////////////////////////////////
// brute force
////////////////
// Time Complexity: O(2^15)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void solve(vector<int> nums, int index, vector<int> output, set<vector<int>>& ans){
        if(index >= nums.size()){
            if(output.size()>1) ans.insert(output);
            return;
        }
        // not adding current number at index
        solve(nums, index+1, output, ans);
        // add the number at index if no value in vector or the number is >= last one
        if(output.size()==0 || nums[index] >= output.back()){
            output.push_back(nums[index]);
            solve(nums, index+1, output, ans);
            output.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> output;
        set<vector<int>> ans;

        solve(nums, 0, output, ans);
        // return as vector
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};