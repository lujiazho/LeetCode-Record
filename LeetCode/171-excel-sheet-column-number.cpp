///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (int i=0 ; i<columnTitle.length() ; i++){
            res += int(columnTitle[i]-'A'+1)*pow(26, columnTitle.length()-1-i);
        }
        return res;
    }
};