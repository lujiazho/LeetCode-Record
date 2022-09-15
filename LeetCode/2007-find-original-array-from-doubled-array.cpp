///////////////////////////////////////////////////////////////////////////////////////////////
// nor hard, use sort for matching from small to large
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return vector<int>{};
        vector<int> res;
        unordered_map<int, int> m; // val:count
        for (auto num:changed) m[num] += 1;
        sort(changed.begin(), changed.end());
        for (auto num:changed) {
            if ((num != 0 && m[num] > 0 && m[num*2] > 0) || (num == 0 && m[num] > 1)) {
                m[num*2] -= 1;
                m[num] -= 1;
                res.push_back(num);
            }            
        }
        return res.size() == changed.size()/2 ? res : vector<int>{};
    }
};