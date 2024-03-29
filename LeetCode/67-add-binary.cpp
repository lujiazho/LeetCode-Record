///////////////////////////////////////////////////////////////////////////////////////////////
// just a little bit complex
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0, nex; // carry
        int idx_a = a.length()-1, idx_b = b.length()-1;
        vector<int> v;
        // simulate addition
        while (idx_a >= 0 && idx_b >= 0){
            nex = c + int(a[idx_a--]) + int(b[idx_b--]) - 96;
            v.push_back(nex%2);
            c = nex/2;
        }
        // one still has left
        while (idx_a >= 0 || idx_b >= 0){
            nex = 0;
            if (idx_a >= 0) nex = c+int(a[idx_a--])-48;
            if (idx_b >= 0) nex = c+int(b[idx_b--])-48;
            v.push_back(nex%2);
            c = nex/2;
        }
        if (c > 0) v.push_back(1);
        
        string res = "";
        for (int i=v.size()-1 ; i>=0 ; i--) res += char(v[i]+48);
        return res;
    }
};
