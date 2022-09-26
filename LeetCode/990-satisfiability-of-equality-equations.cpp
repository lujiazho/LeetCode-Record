///////////////////////////////////////////////////////////////////////////////////////////////
// standard union
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool compare(string& a, string& b){
        return (a.substr(1, 2) > b.substr(1, 2));
    }
    vector<int> father;
    bool equationsPossible(vector<string>& equations) {
        for (int i=0 ; i<26 ; i++) 
            father.push_back(i);

        // let == come first to build union and use != to varify
        sort(equations.begin(), equations.end(), compare);

        for (int i=0; i<equations.size() ; i++) {
            string s = equations[i];
            int a = s[0] - 'a', b = s[3] - 'a';
            int fa = find(a), fb = find(b);
            if (s.substr(1, 2) == "==") {
                father[fa] = fb;
            } else {
                if (fa == fb)
                    return false;
            }
        }
        return true;
    }
    int find(int x) {
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }
};