///////////////////////////////////////////////////////////////////////////////////////////////
// two traversal, left to right, and right to left, then take union area, then minus columns
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>> u;
        int h = height[0];
        for (int i=0 ; i<height.size() ; i++) {
            if (height[i] > h) {
                h = height[i];
            }
            u.push_back(make_pair(h, 0));
        }        
        h = height.back();
        for (int i=height.size()-1 ; i>=0 ; i--) {
            if (height[i] > h) {
                h = height[i];
            }
            u[i].second = h;
        }
        // take union
        vector<int> union_;
        for (int i=0 ; i<u.size() ; i++) union_.push_back(min(u[i].first, u[i].second));
        
        // minus columns volumn
        return accumulate(union_.begin(), union_.end(), 0) - accumulate(height.begin(), height.end(), 0);
    }
};