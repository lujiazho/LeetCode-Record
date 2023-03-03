///////////////////////////////////////////////////////////////////////////////////////////////
// hard kmp
////////////////
// Time Complexity: O(mn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int strStr(string haystack, string needle) {
        string p = " " + needle; // starts from 1
        string s = " " + haystack; // starts from 1
        int next_[int(1e4+10)]; // starts from 1

        // get next array for needle
        int j = 0;
        for (int i=2 ; i<=needle.size() ; i++) {
            while (j && p[i] != p[j+1]) j = next_[j];
            if (p[i] == p[j+1]) j += 1 ;
            next_[i] = j;
        }

        j = 0;
        for (int i=1 ; i<=haystack.size() ; i++) {
            while (j && s[i] != p[j+1]) j = next_[j];
            if (s[i] == p[j+1]) j += 1;
            if (j == needle.size()) return i - j;
        }

        return -1;
    }
};