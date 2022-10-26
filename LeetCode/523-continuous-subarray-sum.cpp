///////////////////////////////////////////////////////////////////////////////////////////////
// crazy math, to find a continuous window W that is multiple of k, we assume W sum is n*k
// then if W really exist, we add some other window X to previous of it, we get X, W
// then you could find that because W % k == 0, so (X + W) % k = X % k + W % k = X % k
// Therefore, if we want to find a window that is a multiple of k
// we only need to find two prefix sum that have the same value of remainder w.r.t k
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map{{0, -1}}; // record all reminders of previous prefixs, and its idx
        int runningSum = 0;
        for (int i=0 ; i<nums.size() ; i++) {
            runningSum += nums[i];
            if (k != 0) runningSum %= k; 
            auto prev = map.find(runningSum);
            if (prev != map.end()) {
                if (i - prev->second > 1) return true;
            }
            else map[runningSum] = i;
        }
        return false;
    }
};