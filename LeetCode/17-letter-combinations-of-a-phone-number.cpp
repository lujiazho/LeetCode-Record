///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(3^8)
// Space Complexity: O(3^8)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> v;
    string dig, cur="";
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        for (int i=0 ; i<10 ; i++)
            v.push_back("");
        v[2] = "abc";
        v[3] = "def";
        v[4] = "ghi";
        v[5] = "jkl";
        v[6] = "mno";
        v[7] = "pqrs";
        v[8] = "tuv";
        v[9] = "wxyz";
        
        dig = digits;
        
        dfs(0);
        
        return res;
    }
    void dfs(int idx){
        if (idx == dig.length()){
            if (cur.length())
                res.push_back(cur);
            return;
        }
        for (char ch:v[int(dig[idx]-'0')]){
            cur += ch;
            dfs(idx+1);
            cur.pop_back();
        }
    }
};