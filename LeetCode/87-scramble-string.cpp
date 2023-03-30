///////////////////////////////////////////////////////////////////////////////////////////////
// complex method
////////////////
// Time Complexity: O((n^2)logn)
// Space Complexity: O((n^2)logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if(s2.size() != n) return false;
        if(s1 == s2) return true;
        if(n == 1) return false; // same length of 1 and not equal
        
        string key = s1+" "+s2;

        if(mp.find(key) != mp.end()) return mp[key];
        
        for(int i=1 ; i<n ; i++) {
            bool withoutswap = (isScramble(s1.substr(0,i),s2.substr(0,i)) &&
                isScramble(s1.substr(i),s2.substr(i)));
            
            if(withoutswap) return true;
            
            bool withswap = (isScramble(s1.substr(0,i),s2.substr(n-i)) &&
                isScramble(s1.substr(i),s2.substr(0,n-i)));
            
            if(withswap) return true;
        }
        
        return mp[key] = false;
    }
};