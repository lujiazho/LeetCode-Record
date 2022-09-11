///////////////////////////////////////////////////////////////////////////////////////////////
// hard but this solution has the same idea as mine
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess(n);
        
        for (int i = 0; i < n; ++i)
            ess[i] = {efficiency[i], speed[i]};
        // sort by efficiency first and speed second, in descending order
        sort(rbegin(ess), rend(ess));
        
        long sumS = 0, res = 0;
        priority_queue <int, vector<int>, greater<int>> pq; // min heap
        
        // for each efficiency from large to small, we keep all spees in order and remove smaller one
        for(auto& [e, s]: ess){
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % (int)(1e9+7);
    }
};