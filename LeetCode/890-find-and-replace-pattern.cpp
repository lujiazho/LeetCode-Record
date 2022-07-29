///////////////////////////////////////////////////////////////////////////////////////////////
// not helpful problem
////////////////
// Time Complexity: O(len*(n^2))
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int n = pattern.size();
        for (auto word:words){
            vector<int> mapping(26, -1);
            unordered_set<int> used;
            int flag = 1;
            for (int i=0 ; i<n ; i++){
                if (mapping[pattern[i]-'a'] == -1) {
                    if (used.find(word[i]-'a') == used.end()){
                        mapping[pattern[i]-'a'] = word[i]-'a';
                        used.insert(word[i]-'a');
                    }else{
                        flag = 0;
                        break;
                    }
                }else if (mapping[pattern[i]-'a'] != word[i]-'a'){
                    flag = 0;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }
};