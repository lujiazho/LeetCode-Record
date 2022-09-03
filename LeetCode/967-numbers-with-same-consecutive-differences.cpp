///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_set<int> res;
    int K;
    vector<int> numsSameConsecDiff(int n, int k) {
        K = k;
        // start from each digit
        for (int num = 1; num <= 9; num++) 
            dfs(num, n - 1);
        return vector<int>(res.begin(), res.end());
    }
    // n: count of num we need to get length n
    void dfs(int num, int n) {
        if (n == 0) 
            res.insert(num);
        else {
            int last = num % 10;
            // larger one
            if (last + K <= 9) dfs(num * 10 + last + K, n - 1);
            // smaller one
            if (last - K >= 0) dfs(num * 10 + last - K, n - 1);
        }
    }
};