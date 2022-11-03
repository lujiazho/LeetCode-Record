///////////////////////////////////////////////////////////////////////////////////////////////
// not really easy before I saw the solution of others
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        // unpaired only indicates the num of unpaired same-letter words
        int unpaired = 0, ans = 0;
        
        for (string w: words) {
            if (w[0] == w[1]) { // same letters
                if (m[w] > 0) { // already has one pair like this
                    unpaired--;
                    m[w]--;
                    ans += 4; // use to make a mirror
                }else {
                    m[w]++;
                    unpaired++;
                }
            }else { // letters are different
                string rev = w;
                reverse(rev.begin(), rev.end());
                if (m[rev] > 0) { // if can find its mirror words
                    ans += 4; // use it to make a mirror
                    m[rev]--;
                }else m[w]++;
            }
        }
        // let same-letter word be the center
        if (unpaired > 0) ans += 2;
        return ans;
    }
};