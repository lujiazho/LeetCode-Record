///////////////////////////////////////////////////////////////////////////////////////////////
// just watch out for edge cases
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int state = 1; // default up
        for (int i=1 ; i<arr.size() ; i++){
            if (arr[i] > arr[i-1]){
                if (state) continue;
                return false;
            }else if (arr[i] < arr[i-1] && i!=1){
                if (!state) continue;
                state = 0;
            }else
                return false;
        }
        if (state) return false;
        return true;
    }
};