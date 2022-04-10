///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (int i=0 ; i<ops.size() ; i++){
            if (ops[i] == "+")
                v.push_back(v[v.size()-1] + v[v.size()-2]);
            else if (ops[i] == "D")
                v.push_back(v[v.size()-1]*2);
            else if (ops[i] == "C")
                v.pop_back();
            else
                v.push_back(stoi(ops[i]));
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};