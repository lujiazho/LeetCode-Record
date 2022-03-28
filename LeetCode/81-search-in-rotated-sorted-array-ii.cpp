///////////////////////////////////////////////////////////////////////////////////////////////
// this is straight forward
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for (int i=0 ; i<nums.size() ; i++){
            if (nums[i] == target) return true;
        }
        return false;
    }
};


// this is O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1, mid;
        // find the pivot
        while (i < j){
            mid = (i+j+1)>>1;
            if (nums[mid] == nums[i] && nums[mid] == nums[j]){
                i++;
                j--;
                if (nums[i] < nums[i-1]){ // this is a special case, the highest point might be the same as last and be removed
                    j = i-1;
                    break;
                }
            }else if (nums[mid] >= nums[i])
                i = mid;
            else
                j = mid-1;
        }
        int pivot = j;
        // check location
        if (target >= nums[0]){
            i = 0;
            j = pivot;
        }else{
            i = pivot+1;
            j = nums.size()-1;
        }
        // binary search
        while (i<j){
            mid = (i+j+1)>>1;
            if (nums[mid] <= target)
                i = mid;
            else
                j = mid - 1;
        }
        return nums[j]==target?true:false;
    }
};