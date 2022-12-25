///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> res;

        for (int i=0 ; i<queries.size() ; i++) {
            int s = 0;
            for (int j=0 ; j<nums.size() ; j++) {
                s += nums[j];
                if (s > queries[i]) {
                    res.push_back(j);
                    break;
                }
            }
            if (res.size() != i+1) res.push_back(nums.size());
        }
        return res;
    }
};