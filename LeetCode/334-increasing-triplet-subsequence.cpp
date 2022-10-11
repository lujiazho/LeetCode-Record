///////////////////////////////////////////////////////////////////////////////////////////////
// not easy to think of this one traversal solution
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // c1: seen smallest element, c2: seen smallest but > c1 element
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1) {
                c1 = x;
            } else if (x <= c2) {
                c2 = x;
            } else {
                return true;
            }
        }
        return false;
    }
};