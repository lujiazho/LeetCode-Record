///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string reverseWords(string s) {
        string res = "", cur = "";
        for (int i=0 ; i<s.length() ; i++) {
            if (s[i] != ' ') cur += s[i];
            else {
                reverse(cur);
                res += cur + ' ';
                cur = "";
            }
        }
        if (cur.length()) {
            reverse(cur);
            res += cur;
        }
        return res;
    }
    void reverse(string& s){
        int i = 0;
        int j = s.length()-1;
        
        while(i <= j){
            swap(s[i], s[j]);
            i ++; j --;
        }
    }
};