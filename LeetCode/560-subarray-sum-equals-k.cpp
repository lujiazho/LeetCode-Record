///////////////////////////////////////////////////////////////////////////////////////////////
// classic
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        m[0].push_back(-1);
        int res = 0;
        int sum = 0;
        for (int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            auto get_sm = m.find(sum-k);
            if (get_sm != m.end()){
                res += m[sum-k].size();
            }
            m[sum].push_back(i);
        }
        return res;
    }
};