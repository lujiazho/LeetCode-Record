///////////////////////////////////////////////////////////////////////////////////////////////
// brilliant solution from others
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> LA, LB;
        int N = img1.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i)
            if (img1[i / N][i % N] == 1)
                LA.push_back(i / N * 35 + i % N);
        for (int i = 0; i < N * N; ++i)
            if (img2[i / N][i % N] == 1)
                LB.push_back(i / N * 35 + i % N);
        // if any combination has the same diff, they must be both in the overlap of same transformation
        for (int i : LA) for (int j : LB) count[i - j]++;
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res;
    }
};