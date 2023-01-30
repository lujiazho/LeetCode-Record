///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int v[40];
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        if (v[n] != 0) return v[n];
        else v[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return v[n];
    }
};