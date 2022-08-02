///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, just go and change, if change num > 1, then it's false, or if cannot change, return false
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for (int i=0 ; i<nums.size()-1 ; i++){
            if (nums[i] > nums[i+1]){
                if (flag == 1) return false;
                int ok0 = 0, ok1 = 0;
                if (i-1 >= 0 && nums[i+1] >= nums[i-1]){
                    ok0 = 1;
                }
                if (i-1 < 0) ok0 = 1;
                if (i+2 < nums.size() && nums[i] <= nums[i+2]){
                    ok1 = 1;
                }
                if (i+2 >= nums.size()) ok1 = 1;
                if (ok0 || ok1) flag = 1;
                else return false;
            }
        }
        return true;
    }
};

// a more clear solution
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for (int i=1 ; i<nums.size() ; i++){
            if (nums[i-1] > nums[i]){
                if (flag == 1) return false;

                if (i-2 >= 0){
                    if (nums[i-2] <= nums[i]){
                        nums[i-1] = nums[i];
                        flag = 1;
                    }else if (nums[i-2] > nums[i] && nums[i-2] <= nums[i-1]){
                        nums[i] = nums[i-1];
                        flag = 1;
                    }else return false;
                }else {
                    nums[i-1] = nums[i];
                    flag = 1;
                }
            }
        }
        return true;
    }
};
