///////////////////////////////////////////////////////////////////////////////////////////////
// vague problem description
// solution from https://leetcode.com/problems/push-dominoes/discuss/787845/O(N)-C%2B%2B-Easy-Solution.-greater90
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> l(n, 0), r(n, 0);
        char prev = '.';
        int count = 1;
        for(int i=0; i<n; i++){
            if(s[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(s[i] == 'L') prev = 'L';
            if(prev == 'R' && s[i] == '.') r[i] = count++;
        }
        prev = '.';
        count = 1;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(s[i] == 'R') prev = 'R';
            if(prev == 'L' && s[i] == '.') l[i] = count++;
        }
        string ans = "";
        for(int i=0; i<n; i++){
            if(!l[i] && !r[i]) ans += s[i];
            else if(!l[i]) ans += 'R';
            else if(!r[i]) ans += 'L';
            else if(l[i] == r[i]) ans += '.';
            else if(l[i] > r[i]) ans += 'R';
            else ans += 'L';
        }
        return ans;
    }
};