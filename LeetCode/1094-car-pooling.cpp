///////////////////////////////////////////////////////////////////////////////////////////////
// easy, like prefix sum
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int v[1000 + 6] = {0};
        int max_ = 0;
        for (int i=0 ; i<trips.size() ; i++){
            if (trips[i][2] > max_){
                max_ = trips[i][2];
            }
            v[trips[i][1]] += trips[i][0];
            v[trips[i][2]] += -trips[i][0];
        }
        if (v[0] > capacity){
            return false;
        }
        for (int i=1 ; i<=max_ ; i++){
            v[i] += v[i-1];
            if (v[i] > capacity){
                return false;
            }
        }
        return true;
    }
};