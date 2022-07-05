///////////////////////////////////////////////////////////////////////////////////////////////
// a little interesting
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num:nums) s.insert(num);
        
        int res = 0;

        // we search x+1, x+2... for each x basically
        for (auto num:s) {
            // here we first check if x-1 exists, if yes, we would go through x
            // so in total, this code wouldn't exceed O(n) in time complexity
            if (s.count(num - 1) == 0) {
                int cur = num;
                int curLen = 1;

                // check x+1, x+2... until it's not in set
                while (s.count(cur + 1)) {
                    cur += 1;
                    curLen += 1;
                }

                // record maximum length
                res = max(res, curLen);
            }
        }
        return res;
    }
};