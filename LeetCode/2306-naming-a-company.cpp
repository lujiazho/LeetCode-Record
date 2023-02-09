///////////////////////////////////////////////////////////////////////////////////////////////
// not really that hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long disName = 0;
        vector<unordered_set<string>> arr(26);
        for (string s : ideas) arr[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                unordered_set<string> set; // repetition string in both letters only keep one
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                // repetition string will be subtracted in both side
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        // the order of concatenation matters
        return disName * 2;
    }
};