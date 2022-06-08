///////////////////////////////////////////////////////////////////////////////////////////////
// brilliant algorithm
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int removePalindromeSub(string s) {
        // because only two types of letters, we at most need 2 steps to remove it all
        for(int i = 0, j = s.size() - 1; i < j; i++, j--)
            if(s[i] != s[j]) return 2;
        // only when the whole string is palindromic, then return 1
        return 1;
    }
};