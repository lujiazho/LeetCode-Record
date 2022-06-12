///////////////////////////////////////////////////////////////////////////////////////////////
// prefix sum + slide window
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> accsum(nums);
        for (int i=1 ; i<nums.size() ; i++) accsum[i] += accsum[i-1];
        
        unordered_map<int, int> s;
        int i=0, j=0;
        int res = 1;
        while (j<nums.size()){
            if (s[nums[j]] == 0){
                s[nums[j]] = 1;
            }else{
                while (s[nums[j]]>0){
                    s[nums[i++]] --;
                }
                s[nums[j]] = 1;
            }
            if (i>0) res = max(res, accsum[j]-accsum[i-1]);
            else res = max(res, accsum[j]);
            j ++;
        }
        return res;
    }
};