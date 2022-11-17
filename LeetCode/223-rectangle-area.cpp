///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(logn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int guessNumber(int n) {
        long long st = 1, ed = n;
        while (1) {
            long long mid = (st+ed) >> 1;
            if (guess(mid) == 0) {
                return mid;
            } else if (guess(mid) == 1) {
                st = mid + 1;
            } else {
                ed = mid - 1;
            }
        }
    }
};