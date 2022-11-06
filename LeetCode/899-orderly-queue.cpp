///////////////////////////////////////////////////////////////////////////////////////////////
// hard, kind of like math
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            // if k > 1, we can either rotate the string
            // or rotate the string without the first one
            // as long as k >= 2, we can swap any two adjacent characters
            // which means we can using bubble sort to just sort it to minimum state
            sort(s.begin(), s.end());
            return s;
        }
        // when k=1, we can only rotate the string to find the minimum one
        string res = s;
        for (int i = 1; i < s.length(); i++)
            res = min(res, s.substr(i) + s.substr(0, i));
        return res;
    }
};