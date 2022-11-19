///////////////////////////////////////////////////////////////////////////////////////////////
// hard, like Computer graphics algo
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        auto cross = [](vector<int>& B, vector<int>& A, vector<int>& T) -> int
        {
            return (T[1]-B[1])*(B[0]-A[0]) - (B[1]-A[1])*(T[0]-B[0]);
        };
        
        sort(trees.begin(), trees.end());
        
        vector<vector<int>> U;
        vector<vector<int>> L;
        
        for (vector<int> T : trees)
        {
            // each time before we add new, check if previous ones are valid
            // it's valid if and only if the angle between current tree and 
            // previous two trees are [clockwise], which represents a convex hull
            // we do this by check the sign of their cross product
            while (U.size() >= 2 and cross(U[U.size()-1],U[U.size()-2],T) < 0)
                U.pop_back();
            // just add it to upper fence
            U.push_back(T);

            // must be [counterclockwise]
            while (L.size() >= 2 and cross(L[L.size()-1],L[L.size()-2],T) > 0)
                L.pop_back();
            // just add it to lower fence
            L.push_back(T);
        }
        // concat upper and lower
        U.insert(U.end(), L.begin(), L.end());
        // get rid of repetition
        set<vector<int>> unique(U.begin(), U.end());
        
        return vector<vector<int>>(unique.begin(), unique.end());;
    }
};