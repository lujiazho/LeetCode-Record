///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.length())
            return false;
        unordered_set<string> set;
        for (int i=0 ; i<=s.length()-k ; i++)
            set.insert(s.substr(i, k));
        return set.size()==pow(2,k)?true:false;
    }
};