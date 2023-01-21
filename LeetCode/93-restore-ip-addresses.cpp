///////////////////////////////////////////////////////////////////////////////////////////////
// brute force
////////////////
// Time Complexity: O(3^20)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> ans;
    bool valid(string temp){
        if(temp.size()>3 || temp.size()==0) return false; // length
        if(temp.size()>1 && temp[0]=='0')   return false; // leading 0
        if(stoi(temp)>255) return false; // > 255
        return true;
    }

    void solve(string output, int idx, string s, int dots){
        // already added 3 dots, check the remaining
        if(dots == 3){
            if(valid(s.substr(idx))) ans.push_back(output+s.substr(idx));
            return;
        }
        int n = s.size();
        // traverse length from 1 to 3
        for(int i=idx ; i<min(idx+3, n) ; i++){
            if(valid(s.substr(idx, i-idx+1))){
                output.push_back(s[i]);
                output.push_back('.');
                solve(output, i+1, s, dots+1);
                output.pop_back();
            }
        }

    }

    vector<string> restoreIpAddresses(string s) {
        string res;
        solve(res, 0, s, 0);
        return ans;
    }
};