///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int cur = 0, n=cardPoints.size();
        int min = INT_MAX;
        int idx = -1;
        int sum = 0;
        for (int i=0 ; i<n-k ; i++)
            cur += cardPoints[i];
        sum = cur;
        if (cur < min){
            min = cur;
            idx = 0;
        }
        for (int i=n-k ; i<n ; i++){
            sum += cardPoints[i];
            cur += cardPoints[i];
            cur -= cardPoints[i-(n-k)];
            if (cur < min){
                min = cur;
                idx = 0;
            }
        }
        return sum - min;
    }
};