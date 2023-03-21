///////////////////////////////////////////////////////////////////////////////////////////////
// good solution
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  cnt = 0, zeroSubarraysEndingAtCurrentIndex = 0;
        for (int n : nums) {
            // only add new part
            if (n == 0) cnt += ++zeroSubarraysEndingAtCurrentIndex;
            else zeroSubarraysEndingAtCurrentIndex = 0;
        }
        return cnt;
    }
};