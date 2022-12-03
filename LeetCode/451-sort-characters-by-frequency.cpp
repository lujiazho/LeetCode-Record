///////////////////////////////////////////////////////////////////////////////////////////////
// hard thing is to write the sort in c++ syntax
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        // record frequency
        for (char ch : s) counts[ch] ++;
        
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        });
        return s;
    }
};