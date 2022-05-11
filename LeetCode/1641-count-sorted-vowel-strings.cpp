///////////////////////////////////////////////////////////////////////////////////////////////
// not hard, I used the idea of hypergeometric
////////////////
// Time Complexity: O(50^5)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int countVowelStrings(int n) {
        int res = 0;
        for (int i=0 ; i<=n ; i++){
            for (int j=0 ; j<=n ; j++){
                for (int k=0 ; k<=n ; k++){
                    for (int l=0 ; l<=n ; l++){
                        for (int m=0 ; m<=n ; m++){
                            if (i+j+k+l+m == n){
                                res += 1;
                            }else if (i+j+k+l+m > n)
                                break;
                        }
                    }
                }
            }
        }
        return res;
    }
};