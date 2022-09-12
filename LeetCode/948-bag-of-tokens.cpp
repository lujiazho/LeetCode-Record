///////////////////////////////////////////////////////////////////////////////////////////////
// a very clear solution
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int res = 0, scores = 0, i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i++];
                res = max(res, ++scores);
            } else if (scores > 0) {
                scores--;
                power += tokens[j--];
            } else {
                break;
            }
        }
        return res;
    }
};