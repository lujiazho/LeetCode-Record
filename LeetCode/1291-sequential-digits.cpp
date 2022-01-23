///////////////////////////////////////////////////////////////////////////////////////////////
// easy, 应该是数位统计DP
////////////////
// Time Complexity: O(9*(digit_num**2))
// Space Complexity: O(9*(digit_num**2)), hard to calculate, here only suppose each time we push back
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v, res;
        int digit_low = 0, digit_high = 0;
        int l = low, h = high;
        while (l){
            digit_low += 1;
            l /= 10;
        }
        while (h){
            digit_high += 1;
            h /= 10;
        }
        int from = 0;
        for (int j=1 ; j<digit_low ; j++){
            from = from*10 + j;
        }
        for (int i=digit_low ; i<=digit_high ; i++){
            from = from*10 + i;
            int fromx = from;
            while (1){
                if (!(fromx%10)) break;
                if (fromx >= low && fromx <= high) res.push_back(fromx);
                int k = i;
                int add = 1;
                while (k--){
                    fromx += add;
                    add *= 10;
                }
            }
        }
        return res;
    }
};