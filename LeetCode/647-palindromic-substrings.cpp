///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O((n^2)*(n/2))
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i=0 ; i<s.length() ; i++){
            for (int j=i ; j<s.length() ; j++){
                res += isPalindrome(s.substr(i, j-i+1));
            }
        }
        return res;
    }
    int isPalindrome(string x){
        for (int i=0 ; i<x.length()/2 ; i++)
            if (x[i] != x[x.length()-i-1]) return 0;
        return 1;
    }
};