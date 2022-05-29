///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(max(n*n, n*m)), n is len of words, m is len of words[i]
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> v;
        for (int i=0 ; i<words.size() ; i++){
            int val = 0;
            for (int j=0 ; j<words[i].length() ; j++){
                if ((val>>(words[i][j] - 'a'))%2==0)
                    val += 1 << (words[i][j] - 'a');
            }
            v.push_back(val);
        }
        int res = 0;
        for (int i=0 ; i<v.size() ; i++)
            for (int j=i+1 ; j<v.size() ; j++)
                if (!(v[i] & v[j])){
                    int val = words[i].length()*words[j].length();
                    res = max(res, val);
                }
        return res;
    }
};