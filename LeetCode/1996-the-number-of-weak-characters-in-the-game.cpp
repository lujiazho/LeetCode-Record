///////////////////////////////////////////////////////////////////////////////////////////////
// a little interesting
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        // we want the order of defense is from large to small when the attack is the same
        // so we would count them in the ans
        sort(properties.begin(), properties.end(), comp);
        int mtn = INT_MIN; // max number of defense
        int ans = 0;

        // from back to front, the front one must have smaller attack 
        // (except same attack, that's why we sort it in reverse on defense)
        for (int i = properties.size() - 1; i >= 0; i--)
        {
           if (properties[i][1] < mtn) // if the second parameter is also less increase the ans
                ans++;
           mtn = max(mtn, properties[i][1]);
        }
        return ans;
    }
};