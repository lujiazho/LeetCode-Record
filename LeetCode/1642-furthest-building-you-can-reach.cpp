///////////////////////////////////////////////////////////////////////////////////////////////
// binary search + sort + greedy algo
////////////////
// Time Complexity: O(logn*(nlogn))
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> hdiff;
        hdiff.push_back(0);
        for (int i=1 ; i<heights.size() ; i++){
            int diff = heights[i]-heights[i-1];
            hdiff.push_back(max(0, diff));
        }
        int st=0, ed=hdiff.size()-1;
        while (st < ed){
            int mid = (st+ed+1)>>1;
            vector<int> v(hdiff.begin(), hdiff.begin() + mid+1);
            sort(v.begin(), v.end());
            int sum_ = 0;
            for (int i=0 ; i<int(v.size()-ladders) ; i++){
                sum_ += v[i];
            }
            if (sum_ <= bricks)
                st = mid;
            else
                ed = mid - 1;
        }
        return ed;
    }
};