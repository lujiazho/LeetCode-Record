///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    // check the weight capacity is enough or not
    bool check(vector<int>& weights, int days, int capacity){
        int requiredDays = 1;
        int currWeight = 0;
        for(int i : weights){
            if(currWeight + i > capacity){
                requiredDays++;
                currWeight = 0;
            }
            currWeight += i;
        }
        if(requiredDays > days) return false;
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // get minimum lower and maximum upper bound
        int l = 0, r = 0, mid;
        for(int w : weights){
            l = max(l, w);
            r += w;
        }

        while(l < r){
            mid = (l+r)>>1;
            if(check(weights, days, mid)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};