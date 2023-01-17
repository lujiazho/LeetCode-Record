///////////////////////////////////////////////////////////////////////////////////////////////
// tricky solution
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count_flip = 0, count_one = 0;
        for (auto i : s) { 
            if (i == '1') count_one++;
            else{
                // means flip current 0 zero to one
                count_flip++;
                // count_one means flip before 1's to zero
                count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};