///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (auto ch:magazine) m[ch] += 1;
        
        for (auto ch:ransomNote){
            if (m[ch] <= 0) return false;
            m[ch] -= 1;
        }
        return true;
    }
};