///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(max(m, n))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26, 0);
        for (int i=0 ; i<words2.size() ; i++){
            vector<int> cur(26, 0);
            for (int j=0 ; j<words2[i].size() ; j++) cur[words2[i][j]-'a'] += 1;
            for (int j=0 ; j<26 ; j++){
                if (cur[j] > v[j]) v[j] = cur[j];
            }
        }
        
        vector<string> res;
        for (int i=0 ; i<words1.size() ; i++){
            vector<int> cur(26, 0);
            for (int j=0 ; j<words1[i].size() ; j++) cur[words1[i][j]-'a'] += 1;
            int flag = 1;
            for (int j=0 ; j<26 ; j++) {
                if (cur[j] < v[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(words1[i]);
        }
        return res;
    }
};