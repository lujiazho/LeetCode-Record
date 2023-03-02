///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;

        char curr = chars[0];
        int count = 1;
        string s = "";
        for (int i=1 ; i<chars.size() ; i++) {
            if (i < chars.size() && chars[i] == curr) count++;
            else {
                s += curr;
                if (count > 1) s += to_string(count);
                curr = chars[i];
                count = 1;
            }
        }
        // last one
        s += curr;
        if (count > 1) s += to_string(count);

        for (int i=0 ; i<s.size() ; i++) {
            chars[i] = s[i];
        }
        return s.size();
    }
};