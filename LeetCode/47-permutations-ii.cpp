///////////////////////////////////////////////////////////////////////////////////////////////
// not hard but not friendly as well
////////////////
// Time Complexity: O(8^8)
// Space Complexity: O(8^8)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int N;
    unordered_set<string> used;
    vector<vector<int>> res;
    unordered_set<int> s;
    vector<int> cur;
    vector<int> my_nums;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        N = nums.size();
        my_nums = nums;
        dfs();
        return res;
    }
    void dfs(){
        if (cur.size() == N){
            string str = "";
            vector<int> add;
            for (auto x:cur){
                str += my_nums[x] + '_';
                add.push_back(my_nums[x]);
            }
            
            if (used.find(str) == used.end()){
                res.push_back(add);
                used.insert(str);
            }
            return;
        }
        for (int i=0 ; i<N ; i++){
            if (s.find(i) == s.end()){
                cur.push_back(i);
                s.insert(i);
                dfs();
                cur.pop_back();
                s.erase(i);     
            }
        }
    }
};