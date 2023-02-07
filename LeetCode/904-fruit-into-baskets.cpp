///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // map used for storing number of each type in a window
        unordered_map<int, int> mpp;
        // i, j are left and right of the current window
        int i = 0, j = 0, res = 0;
        
        while(j < fruits.size()) {
            mpp[fruits[j]]++;

            if(mpp.size() <= 2) res = max(res, j-i+1);
            else {
                // clear all fruits for one type
                while (mpp.size() > 2) {
                    mpp[fruits[i]] --;
                    if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                    i ++;
                }
            }
            
            j++;
        }

        return res; 
    }
};