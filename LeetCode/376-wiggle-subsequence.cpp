///////////////////////////////////////////////////////////////////////////////////////////////
// many edge cases
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 2){
            if (nums.size() == 1)
                return 1;
            return nums[0]==nums[1]?1:nums.size();
        }
        vector<int> diff;
        for (int i=1 ; i<nums.size() ; i++){
            diff.push_back(nums[i] - nums[i-1]);
        }
        int nex = 0;
        for (int i=0 ; i<diff.size() ; i++){
            if (diff[i] == 0)
                nex += 1;
            else
                break;
        }
        if (nex >= diff.size()) return 1;
        int last = diff[nex];
        int res = 2;
        for (int i=nex+1 ; i<diff.size() ; i++){
            if (diff[i]*last < 0){
                res += 1;
            }
            if (diff[i] != 0)
                last = diff[i];
        }
        return res;
    }
};

// a little more clear
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 3) {
            if (nums.size() == 1) return 1;
            return nums[0]==nums[1]?1:nums.size();
        }
        
        // starting point
        int res = 1;
        
        // state: 1 increase, -1 decrease
        int state = 0;
        
        // for a case that all vals are the same
        int flag = 0;
        if (nums[1] - nums[0]>0) state = 1;
        if (nums[1] - nums[0]<0) state = -1;
        if (state == 0) flag = 1;

        // start from 2
        for (int i=2 ; i<nums.size() ; i++){
            if (state == 1) { // increase
                if (nums[i] - nums[i-1] < 0) { // 0 doesn't change state
                    state = -1;
                    res += 1;
                }
            }else if (state == -1) { // decrease
                if (nums[i] - nums[i-1] > 0) { // 0 doesn't change state
                    state = 1;
                    res += 1;
                }
            }else{ // the edge case that starting from flat ground
                if (nums[i] - nums[i-1] < 0 || nums[i] - nums[i-1] > 0) {
                    // change state depending on slope
                    state = nums[i] - nums[i-1] < 0?-1:1;
                    res += 1;
                }
            }
        }
        return flag==1?res:res + 1;
    }
};

// this is crazy
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size=nums.size(), peak=1, valley=1;
        for(int i=1; i<size; ++i){
            if(nums[i]>nums[i-1]) peak = valley + 1;
            else if(nums[i]<nums[i-1]) valley = peak + 1;
        }
        return max(peak, valley);
    }
};
