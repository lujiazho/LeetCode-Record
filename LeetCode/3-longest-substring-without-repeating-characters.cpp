///////////////////////////////////////////////////////////////////////////////////////////////
// use set to check repetition, and use st and ed to maintain the window
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set_;
        int res = 0, st = 0, ed = 0;
        for (int i=0 ; i<s.length() ; i++){
            auto get = set_.find(s[i]);
            if (get != set_.end()){
                res = max(res, ed-st);
                int j;
                for (j=st ; s[j] != s[i] ; j++){
                    set_.erase(s[j]);
                }
                st = j+1;
            }else{
                set_.insert(s[i]);
            }
            ed += 1;
        }
        res = max(res, ed-st);
        return res;
    }
};