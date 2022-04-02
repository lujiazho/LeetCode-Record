///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validPalindrome(string s) {
        int flag = 1, idx = s.size()-1, i;
        for (i=0 ; i<s.size()/2 ; i++){
            if (s[i] != s[idx-i]) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) return true;
        // delete front
        int st = i+1, ed = idx-i;
        flag = 1;
        while (st < ed){
            if (s[st++] != s[ed--]){
                flag = 0;
                break;
            }
        }
        if (flag == 1) return true;
        
        // delete back
        st = i, ed = idx-i-1;
        flag = 1;
        while (st < ed){
            if (s[st++] != s[ed--]){
                flag = 0;
                break;
            }
        }
        if (flag == 1) return true;
        return false;
    }
};