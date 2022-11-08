///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string makeGood(string s) {
        string ans;
        
        for(int i = 0 ; i < s.size() ; i++) {
            ans.push_back(s[i]);
            // as long as the next can be along with the last one in ans
            while(ans.size() && i<s.size() && (ans.back()==s[i+1]+32 || ans.back()==s[i+1]-32))
            {
                ans.pop_back();
                i++;
            }
        }
        
        return ans;
    }
};