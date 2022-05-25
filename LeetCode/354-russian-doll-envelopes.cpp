///////////////////////////////////////////////////////////////////////////////////////////////
// hard
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(nlogn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare_2_vals(vector<int>& a, vector<int>& b){
        if (a[0] != b[0])
            return (a[0] < b[0]);
        return (a[1] > b[1]); // hight: higher is at front, to avoid two evnelops with same width
    }
    vector<int> maximum;
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare_2_vals);
        
        for (int i=0 ; i<envelopes.size() ; i++){
            int loc = bisect_(envelopes[i][1]);
            if (loc == maximum.size())
                maximum.push_back(envelopes[i][1]);
            else
                maximum[loc] = envelopes[i][1];
        }
        return maximum.size();
    }
    int bisect_(int x){
        int l = 0, r = maximum.size() - 1;
        int loc = r + 1;
        while (l <= r){
            int mid = (l + r) / 2;
            if (maximum[mid] >= x){
                loc = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return loc;
    }
};