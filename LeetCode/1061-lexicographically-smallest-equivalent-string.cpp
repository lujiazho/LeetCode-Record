///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int father[26];
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(father, -1, sizeof(father));
        
        // union
        for (auto i = 0; i < s1.size(); ++i) {
            int x = find(s1[i] - 'a');
            int y = find(s2[i] - 'a');
            // let the smallest one as the root father
            if (x != y) father[max(x, y)] = min(x, y);
        }
        
        for(auto i=0 ; i<baseStr.size() ; i++) 
            baseStr[i] = find(baseStr[i]-'a') + 'a';

        return baseStr;
    }
    int find(int x){
        if(father[x] == -1) return x;
        return father[x] = find(father[x]);
    }
};