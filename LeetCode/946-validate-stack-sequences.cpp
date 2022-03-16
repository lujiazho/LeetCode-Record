///////////////////////////////////////////////////////////////////////////////////////////////
// not really easy but I just finished fast
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if (pushed.empty()) return true;
        vector<int> v;
        int i = 0; // follow pushed
        int j = 0; // follow popped
        while (i < pushed.size()){
            while (i<pushed.size() && (v.empty() || (!v.empty() && v[v.size()-1] != popped[j]))){
                v.push_back(pushed[i]);
                i++;
            }
            while (v.size() && j<popped.size() && v[v.size()-1] == popped[j]){
                v.pop_back();
                j++;
            }
            if (j == popped.size()) return true;
        }
        return false;
    }
};