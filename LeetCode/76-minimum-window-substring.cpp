///////////////////////////////////////////////////////////////////////////////////////////////
// good solution to use vector instead of map, and use remaining to determine if it's a valid window
// In my first glance I only think of using another map and each shift we have to compare the num of chars
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string minWindow(string s, string t) {
        // 128 is for the highest corresponding int in a-zA-Z
        if (s.size() == 0 || t.size() == 0) return "";
        vector<int> remaining(128, 0);
        for (int i = 0; i < t.size(); i++) remaining[t[i]]++;
        
        int required = t.size();
        // start: current left, i: current right
        // left: recorded best left, min: recorded minimum length
        int min = INT_MAX, start = 0, left = 0, i = 0;
        while(i <= s.size() && start < s.size()) {
            if(required) {
                if (i == s.size()) break;
                remaining[s[i]]--;
                // if remaining[s[i]] < 0, meaning we don't need this character
                if (remaining[s[i]] >= 0) required--;
                i++;
            } else {
                // update best window
                if (i - start < min) {
                    min = i - start;
                    left = start;
                }
                // delete leftmost character in current window
                remaining[s[start]]++;
                // if it > 0, meaning we do need it in t string
                if (remaining[s[start]] > 0) required++;
                // shrink this window
                start++;
            }
        }
        return min == INT_MAX? "" : s.substr(left, min);
    }
};