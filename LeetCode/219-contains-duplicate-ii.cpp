///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i=0 ; i<nums.size() ; i++)
            m[nums[i]].push_back(i);
        for (auto p:m) {
            for (int i=1 ; i<p.second.size() ; i++) {
                if (p.second[i] - p.second[i-1] <= k) 
                    return true;
            }
        }
        return false;
    }
};