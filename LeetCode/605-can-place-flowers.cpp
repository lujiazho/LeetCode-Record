///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (!n) return true;
        int len = flowerbed.size();
        for (int i=0 ; i<len ; i++){
            if (!flowerbed[i] && (i==0||!flowerbed[i-1]) && (i==len-1||!flowerbed[i+1])){
                flowerbed[i] = 1;
                if(!--n) break;
            }
        }
        return !n?true:false;
    }
};