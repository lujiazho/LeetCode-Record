///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n && n % 3 == 0)
            n /= 3;
        return n==1?true:false;
    }
};