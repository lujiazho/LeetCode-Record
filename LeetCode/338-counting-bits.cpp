///////////////////////////////////////////////////////////////////////////////////////////////
// easy if use the nlogn method
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i=0 ; i<=n ; i++){
            int count = 0;
            int num = i;
            while(num){
                count += 1;
                num -= num&(-num);
            }
            res.push_back(count);
        }
        return res;
    }
};

// this is the O(n) method by using dp, which is brilliant
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i=1 ; i<=n ; i++){
            res.push_back(res[i>>1]+i%2);
        }
        return res;
    }
};