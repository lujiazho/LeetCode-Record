///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<int> s;
        for (auto ch:sentence) {
            s.insert(ch - 'a');
            if (s.size() == 26) return true;
        }
        return false;
    }
};