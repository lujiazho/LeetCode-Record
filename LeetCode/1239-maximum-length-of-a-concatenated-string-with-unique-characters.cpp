///////////////////////////////////////////////////////////////////////////////////////////////
// literally go through all possible combinations, and stop early if it's not possible
////////////////
// Time Complexity: O(2^n)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxLength(vector<string>& arr, string str = "", int index = 0) {
        //Use set to check if the string contains all unique characters
        unordered_set<char>s(str.begin(), str.end());
        if (s.size() != ((int)str.length())) 
            return 0;
        
        int ret = str.length();
        for (int i = index; i < arr.size(); i++)
            ret = max(ret, maxLength(arr, str+arr[i], i+1));

        return ret;
    }
};