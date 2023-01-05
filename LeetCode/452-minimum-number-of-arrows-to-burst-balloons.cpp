///////////////////////////////////////////////////////////////////////////////////////////////
// greedy algorithm
////////////////
// Time Complexity: O(nlogn), most time spent on sorting
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare_2_vals(vector<int>& a, vector<int>& b){
        if (a[1] != b[1])
            return (a[1] < b[1]);
        return (a[0] < b[0]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare_2_vals);
        int res = 0, arrow = -1;
        for (int i=0 ; i<points.size() ; i++){
            arrow = points[i][1];
            res += 1;
            i += 1;
            while (i<points.size() && points[i][0] <= arrow){
                i += 1;
            }
            i -= 1;
        }
        return res;
    }
};

// or start from 1, but the algorithm is basically the same; also we don't need to sort by the x_start
class Solution {
public:
    static bool compare_2_vals(vector<int>& a, vector<int>& b){
        return (a[1] < b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), compare_2_vals);
        int res = 1, arrow = points[0][1];
        for (int i=1 ; i<points.size() ; i++){
            // skip all balloons that can be shot by current arrow
            while (i<points.size() && points[i][0] <= arrow) i += 1;
            // if still got left ballon, we count next arrow
            if (i < points.size()){
                arrow = points[i][1];
                res += 1;
            }
        }
        return res;
    }
};
