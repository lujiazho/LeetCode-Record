///////////////////////////////////////////////////////////////////////////////////////////////
// classic mono stack problem
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        vector<int> mono_stack;
        int left[len], right[len];
        for (int i=0 ; i<len ; i++){
            while (mono_stack.size() && heights[mono_stack.back()] >= heights[i])
                mono_stack.pop_back();
            left[i] = mono_stack.size()?mono_stack.back():-1;
            mono_stack.push_back(i);
        }
        mono_stack.clear();
        for (int i=len-1 ; i>=0 ; i--){
            while (mono_stack.size() && heights[mono_stack.back()] >= heights[i])
                mono_stack.pop_back();
            right[i] = mono_stack.size()?mono_stack.back():len;
            mono_stack.push_back(i);
        }
        int res = 0;
        for (int i=0 ; i<len ; i++){
            int area = (right[i] - left[i] - 1)*heights[i];
            if (area > res) res = area;
        }
        return res;
    }
};