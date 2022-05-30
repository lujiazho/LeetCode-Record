///////////////////////////////////////////////////////////////////////////////////////////////
// a little annoying
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && (divisor == -1 || divisor == 1)){
            return divisor == -1?INT_MAX:INT_MIN;
        }
        if (dividend == INT_MAX && (divisor == -1 || divisor == 1)){
            return divisor == -1?-INT_MAX:INT_MAX;
        }
        int res = 0;
        if (dividend < 0 && divisor < 0){
            while (dividend <= divisor){
                dividend -= divisor;
                res += 1;
                if (res == INT_MAX)
                    break;
            }
        }else if (dividend > 0 && divisor > 0){
            while (dividend >= divisor){
                dividend -= divisor;
                res += 1;
                if (res == INT_MAX)
                    break;
            }
        }else if (dividend < 0 && divisor > 0){
            while (dividend <= -divisor){
                dividend += divisor;
                res -= 1;
                if (res == INT_MIN)
                    break;
            }
        }else if (dividend > 0 && divisor < 0){
            while (-dividend <= divisor){
                dividend += divisor;
                res -= 1;
                if (res == INT_MIN)
                    break;
            }
        }
        return res;
    }
};