///////////////////////////////////////////////////////////////////////////////////////////////
// not so easy but interesting
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int area = (height.size()-1)*min(height[l], height[r]);
        int cur_l = l, cur_r = r;
        while (cur_l < cur_r){
            if (height[cur_l] < height[cur_r]){
                cur_l += 1;
            }else{
                cur_r -= 1;
            }
            int new_area = min(height[cur_l], height[cur_r]) * (cur_r - cur_l);
            if (new_area > area){
                l = cur_l;
                r = cur_r;
                area = new_area;
            }
        }
        return area;
    }
};