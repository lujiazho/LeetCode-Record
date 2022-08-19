///////////////////////////////////////////////////////////////////////////////////////////////
// not easy to think of this method
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
     bool isPossible(vector<int>& A) {
        // count[i]: count of number i; end[i]: count of sequence ending at number i
        unordered_map<int, int> count, end;
        for (int i: A) count[i]++;

        for (int i: A) {
            if (count[i] == 0) continue;
            if (end[i-1] > 0) { // add to the end
                end[i-1]--;
                end[i]++;
            } else if (count[i+1] > 0 && count[i+2] > 0) { // build a new sequence
                count[i+1]--;
                count[i+2]--;
                end[i+2]++;
            } else {   
                return false;
            }
            count[i]--;
        }
        return true;
    }
};