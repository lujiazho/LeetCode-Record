///////////////////////////////////////////////////////////////////////////////////////////////
// application of binary search
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int min_h = 1<<31, min_eat = 1<<31;
        while (l < r){
            int cur_eat = l+((r-l)>>1);
            int cur_h = 0;
            for (int j=0 ; j<piles.size() ; j++){
                cur_h += ceil(piles[j]*1.0/cur_eat);
            }
            if (cur_h > h){
                l = cur_eat + 1;
            }else{
                r = cur_eat;
            }
        }
        return l;
    }
};