///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> v; // diff:val
        for (int i=0 ; i<arr.size() ; i++) {
            v.push_back(make_pair(abs(arr[i]-x), arr[i]));
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for (int i=0 ; i<k ; i++) {
            res.push_back(v[i].second);
        }
        sort(res.begin(), res.end());
        return res;
    }
};