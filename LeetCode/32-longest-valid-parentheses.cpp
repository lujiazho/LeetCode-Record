///////////////////////////////////////////////////////////////////////////////////////////////
// hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> v;
        v.push_back(-1);
        int res = 0;
        
        for (int i=0 ; i<s.size() ; i++){
            if (s[i] == '(') v.push_back(i);
            else{
                v.pop_back();
                if (v.size())
                    res = max(res, i - v.back());
                else
                    v.push_back(i);
            }
        }
        return res;
    }
};