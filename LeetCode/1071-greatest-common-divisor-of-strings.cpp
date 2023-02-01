///////////////////////////////////////////////////////////////////////////////////////////////
// interesting solution
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // the str1 + str2 must be equal to str2 + str1 because they are both dividable by certain string
        return (str1 + str2 == str2 + str1)? str1.substr(0, gcd(size(str1), size(str2))): "";
    }
};