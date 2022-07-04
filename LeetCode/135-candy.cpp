///////////////////////////////////////////////////////////////////////////////////////////////
// not really hard, use greedy method + sort
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(vector<int> &u, vector<int> &v)
    {
        if (u[0] != v[0])
            return u[0] < v[0];
        return u[1] < v[1];
    }
    int candy(vector<int>& ratings) {
        vector<vector<int>> v;
        vector<int> candies(ratings.size(), 1);
        for (int i=0 ; i<ratings.size() ; i++){
            v.push_back(vector<int>{ratings[i], i});
        }
        sort(v.begin(), v.end(), comp);
        
        for (int i=0 ; i<ratings.size() ; i++){
            int idx = v[i][1];
            if (idx-1 >= 0){
                if (ratings[idx] > ratings[idx-1])
                    candies[idx] = candies[idx-1]+1;
            }
            if (idx+1 < ratings.size()){
                if (ratings[idx] > ratings[idx+1])
                    candies[idx] = max(candies[idx], candies[idx+1]+1);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};