///////////////////////////////////////////////////////////////////////////////////////////////
// tricky
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(vector<int> &u, vector<int> &v)
    {
        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> res;
        // as long as higher people already in array, we can insert one into this array
        // the people behind this one wouldn't affect the results
        for (auto person:people) {
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};