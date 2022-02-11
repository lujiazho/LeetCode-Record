///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m;
        for (int i=0 ; i<s1.length() ; i++) m[s1[i]] += 1;
        unordered_map<char, int> window;
        int num = 0;
        for (int i=0 ; i<s2.length() ; i++){
            num += 1;
            window[s2[i]] += 1;
            if (num == s1.length()){
                int flag = 1;
                for (auto per:m){
                    if (window[per.first] != per.second){
                        flag = 0;
                        break;
                    }
                }
                if (flag) return true;
                num -= 1;
                window[s2[i - num]] -= 1;
            }
        }
        return false;
    }
};