///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        // no way to change it
        if (n < 2) return "";
        
        // change the first "not a" to a
        for (int i = 0; i < n / 2; ++i) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // if all "a", change last one to "b"
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
