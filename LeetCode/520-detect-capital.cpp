///////////////////////////////////////////////////////////////////////////////////////////////
// easy...
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool detectCapitalUse(string word) {
        int num_C = 0, first_loc = -1;
        for (int i=0 ; i<word.length() ; i++){
            // record number of Capitals and the idx of the first one
            if ('A' <= word[i] && word[i] <= 'Z'){
                num_C += 1;
                if (first_loc == -1) first_loc = i;
            }
        }
        // if no capital
        if (!num_C) return true;
        // if all capitals
        if (num_C == word.length()) return true;
        // if only one and it's at the first location
        if (num_C == 1 && !first_loc) return true;
        // not valid
        return false;
    }
};
