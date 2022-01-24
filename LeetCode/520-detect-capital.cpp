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
            if ('A' <= word[i] && word[i] <= 'Z'){
                num_C += 1;
                if (first_loc == -1) first_loc = i;
            }
        }
        if (!num_C) return true;
        if (num_C == word.length()) return true;
        if (num_C == 1 && !first_loc) return true;
        return false;
    }
};