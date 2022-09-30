///////////////////////////////////////////////////////////////////////////////////////////////
// not easy because the input range is too large
// this leads to TLE, because find maximum is too costful
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> lines;
        for (int i=0 ; i<buildings.size() ; i++) {
            int l=buildings[i][0], r=buildings[i][1], h=buildings[i][2];
            lines.push_back({l, -h});
            lines.push_back({r, h});
        }
        // when x is the same, left should be at front of right
        sort(lines.begin(), lines.end());

        multiset<int> heights{0};
        vector<vector<int>> res;
        // record previous key point height and cur key point height
        int pre_point_h=0, cur_point_h=0;
        
        for (int i=0 ; i<lines.size() ; i++) {
            int x=lines[i][0], h=lines[i][1];
            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));
            
            cur_point_h = *max_element(heights.begin(), heights.end());
            
            if (cur_point_h != pre_point_h) {
                res.push_back(vector<int>{x, cur_point_h});
                pre_point_h = cur_point_h;
            }
        }
            
        return res;
    }
};

// because multiset in c++ is ordered, so we directly get the maximum
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> lines;
        for (int i=0 ; i<buildings.size() ; i++) {
            int l=buildings[i][0], r=buildings[i][1], h=buildings[i][2];
            lines.push_back({l, -h});
            lines.push_back({r, h});
        }
        // when x is the same, left should be at front of right
        sort(lines.begin(), lines.end());

        multiset<int> heights{0};
        vector<vector<int>> res;
        // record previous key point height and cur key point height
        int pre_point_h=0, cur_point_h=0;
        
        for (int i=0 ; i<lines.size() ; i++) {
            int x=lines[i][0], h=lines[i][1];
            if (h < 0)
                heights.insert(-h);
            else
                heights.erase(heights.find(h));
            
            cur_point_h = *heights.rbegin();
            
            if (cur_point_h != pre_point_h) {
                res.push_back(vector<int>{x, cur_point_h});
                pre_point_h = cur_point_h;
            }
        }
            
        return res;
    }
};