///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string x = "", y = "";
        for (int i=0 ; i<s.length() ; i++){
            if (s[i] == '#'){
                if (x.length())
                    x.pop_back();
            }
            else
                x += s[i];
        }
        for (int i=0 ; i<t.length() ; i++){
            if (t[i] == '#'){
                if (y.length())
                    y.pop_back();
            }else
                y += t[i];
        }
        return (x == y);
    }
};