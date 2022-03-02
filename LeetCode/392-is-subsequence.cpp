///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (!s.length()) return true;
        int idx = 0;
        for (int i=0 ; i<t.length() ; i++){
            if (s[idx] == t[i]) idx++;
            if (idx == s.length()) return true;
        }
        return false;
    }
};