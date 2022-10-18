///////////////////////////////////////////////////////////////////////////////////////////////
// easy recursion
////////////////
// Time Complexity: O(n*30)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string n_1 = countAndSay(n-1);
        char last = 'a';
        int c = 0;
        string res;
        for (auto ch:n_1) {
            if (ch == last) c += 1;
            else {
                if (c > 0) res += to_string(c) + last;
                last = ch;
                c = 1;
            }
        }
        if (c > 0) res += to_string(c) + last;
        return res;
    }
};