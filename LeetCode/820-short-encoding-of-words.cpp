///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(max(n*m, nlogn))
// Space Complexity: O(n*m)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(string &s1, string &s2)
    {
        return s1.length()>s2.length()?true:false;
    }
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_set<string> s;
        string res = "";
        for (int i=0 ; i<words.size() ; i++){
            if (s.find(words[i]) == s.end())
                res += words[i] + "#";
                for (int j=1 ; j<=words[i].length() ; j++)
                    s.insert(words[i].substr(words[i].length()-j, j));
        }
        return res.length();
    }
};