///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        // decreasing stack
        vector<int> v{temperatures[n-1]};
        vector<int> reduce{0}; // record the number being removed by this number
        temperatures[n-1] = 0;
        for (int i=n-2 ;  i>=0 ; i--) {
            int cur = 0;
            while (v.size() && v.back() <= temperatures[i]) {
                cur += 1 + reduce.back();
                v.pop_back();
                reduce.pop_back();
            }
            v.push_back(temperatures[i]);
            reduce.push_back(cur);
            
            temperatures[i] = (v.size() > 1) ? cur + 1 : 0;
        }
        return temperatures;
    }
};