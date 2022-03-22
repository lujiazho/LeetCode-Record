///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but a little bit confusing
////////////////
// Time Complexity: O(26*n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string getSmallestString(int n, int k) {
        if (n == k) {
            string res = "";
            for (int i=0 ; i<n ; i++) res += "a";
            return res;
        }
        int val = n;
        int idx = n-1;
        vector<char> v;
        for (int i=0 ; i<n ; i++) v.push_back('a');
        while (true){
            v[idx] = 'z';
            val += 25;
            while (val > k){
                val--;
                v[idx]--;
            }
            if (val == k) break;
            idx--;
        }
        string res = "";
        for (int i=0 ; i<n ; i++) res += v[i];
        return res;
    }
};