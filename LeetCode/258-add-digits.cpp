///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int addDigits(int num) {
        while (num > 9){
            int cur = num;
            int sum = 0;
            while (cur){
                sum += cur % 10;
                cur /= 10;
            }
            num = sum;
        }
        return num;
    }
};