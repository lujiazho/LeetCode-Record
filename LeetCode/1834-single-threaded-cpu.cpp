///////////////////////////////////////////////////////////////////////////////////////////////
// not hard just a bit complex
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using pp = pair<int,pair<int,int>>;
        // store in: start, processTime, index
        vector<pp> vtr;
        int n = tasks.size();
        for(int i = 0; i < n; ++i) vtr.push_back({tasks[i][0],{tasks[i][1],i}});
        sort(vtr.begin(),vtr.end());

        // store in: processTime, index, start
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        vector<int> res;

        int i = 0;
        long long curr_time = vtr[i].first;
        // as long as there is still task, we keep in this loop
        while(i < n || !pq.empty()){
            // we push all tasks that should be started to queue
            while(i < n && curr_time >= vtr[i].first){
                pq.push({vtr[i].second.first,{vtr[i].second.second,vtr[i].first}});
                ++i;
            }
            // do the task that has smallest processTime
            curr_time += pq.top().first;
            // store index as return
            res.push_back(pq.top().second.first);
            pq.pop();

            // update current time when queue is empty and the first remaining task can be started
            if(i < n && curr_time < vtr[i].first && pq.empty()) curr_time = vtr[i].first;
        }
        return res;
    }
};