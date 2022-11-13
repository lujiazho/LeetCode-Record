///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, this solution is kind of optimized with in-replace substitution
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int storeIndex = 0;
        for (int i = 0; i < s.size(); i++) {
            // skip all spaces
            if (s[i] != ' ') {
                // add a space if this is not the 0 idx
                if (storeIndex != 0) s[storeIndex++] = ' ';
                int j = i;
                // add a new word (in place)
                while (j < s.size() && s[j] != ' ') { s[storeIndex++] = s[j++]; }
                // reverse only this new word
                reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
                i = j;
            }
        }
        // remove the left part
        s.erase(s.begin() + storeIndex, s.end());
        return s;
    }
};