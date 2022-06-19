///////////////////////////////////////////////////////////////////////////////////////////////
// almost same as yesterday's
////////////////
// Time Complexity: O(n*m)
// Space Complexity: O(s*nlogn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_map<string,vector<string>> pres;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (int i=0 ; i<products.size() ; i++){
            string s = products[i];
            for (int j=1 ; j<=s.length() ; j++){
                pres[s.substr(0,j)].push_back(s);
            }
        }
        vector<vector<string>> res;
        for (int i=1 ; i<=searchWord.length() ; i++){
            vector<string> cur = pres[searchWord.substr(0,i)];
            sort(cur.begin(), cur.end());
            if (cur.size() > 3){
                res.push_back(vector<string>(cur.begin(), cur.begin()+3));
            }else
                res.push_back(cur);
        }
        return res;
    }
};