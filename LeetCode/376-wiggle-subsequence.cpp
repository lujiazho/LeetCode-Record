///////////////////////////////////////////////////////////////////////////////////////////////
// many edge cases
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 2){
            if (nums.size() == 1)
                return 1;
            return nums[0]==nums[1]?1:nums.size();
        }
        vector<int> diff;
        for (int i=1 ; i<nums.size() ; i++){
            diff.push_back(nums[i] - nums[i-1]);
        }
        int nex = 0;
        for (int i=0 ; i<diff.size() ; i++){
            if (diff[i] == 0)
                nex += 1;
            else
                break;
        }
        if (nex >= diff.size()) return 1;
        int last = diff[nex];
        int res = 2;
        for (int i=nex+1 ; i<diff.size() ; i++){
            if (diff[i]*last < 0){
                res += 1;
            }
            if (diff[i] != 0)
                last = diff[i];
        }
        return res;
    }
};