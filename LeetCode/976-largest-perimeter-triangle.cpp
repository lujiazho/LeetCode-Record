///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-1 ; i>=2 ; i--) {
            int a=nums[i], b=nums[i-1], c=nums[i-2];
            if (isTri(a, b, c)) return a + b + c;
        }
        return 0;
    }
    bool isTri(int a, int b, int c) {
        if (a + b > c && a + c > b && b + c > a) return true;
        return false;
    }
};