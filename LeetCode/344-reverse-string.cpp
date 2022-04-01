///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void reverseString(vector<char>& s) {
        int idx = s.size()-1;
        char ch;
        for (int i=0 ; i<s.size()/2 ; i++){
            ch = s[i];
            s[i] = s[idx-i];
            s[idx-i] = ch;
        }
    }
};