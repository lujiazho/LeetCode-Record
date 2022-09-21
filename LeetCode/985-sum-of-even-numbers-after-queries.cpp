///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int even = 0;
        for (auto n:nums) if (n%2==0) even += n;
        
        vector<int> res;
        for (int i=0 ; i<queries.size() ; i++) {
            int idx = queries[i][1];
            int pre = nums[idx];
            int pos = pre + queries[i][0];
            nums[idx] = pos;
            
            if (abs(pre % 2) == 0 && abs(pos % 2) == 0){
                even -= (pre - pos);
            } else if (abs(pre % 2) == 0 && abs(pos % 2) == 1) {
                even -= pre;
            } else if (abs(pre % 2) == 1 && abs(pos % 2) == 0) {
                even += pos;
            } else if (abs(pre % 2) == 1 && abs(pos % 2) == 1) {
                even += 0;
            }
            res.push_back(even);
        }
        return res;
    }
};