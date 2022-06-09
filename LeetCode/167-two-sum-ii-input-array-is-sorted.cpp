///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        int cur = numbers[i] + numbers[j];
        while (cur != target){
            if (cur > target)
                j -= 1;
            else
                i += 1;
            cur = numbers[i] + numbers[j];
        }
        return vector<int>{i+1, j+1};
    }
};