///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(max(len(s)*26, len(p)))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int letters[26] = {0};
        for (int i=0 ; i<p.length() ; i++)
            letters[p[i] - 'a'] += 1;
        int cur[26] = {0};
        vector<int> res;
        for (int i=0 ; i<s.length() ; i++){
            if (i >= p.length()){
                int flag = 1;
                for (int j=0 ; j<26 ; j++)
                    if (letters[j] != cur[j]){
                        flag = 0;
                        break;
                    }
                if (flag) res.push_back(i-p.length());
                cur[s[i-p.length()] - 'a'] -= 1;
            }
            cur[s[i] - 'a'] += 1;
        }
        // check the last part
        int flag = 1;
        for (int j=0 ; j<26 ; j++)
            if (letters[j] != cur[j]){
                flag = 0;
                break;
            }
        if (flag) res.push_back(s.length() - p.length());
        return res;
    }
};