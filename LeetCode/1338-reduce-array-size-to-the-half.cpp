///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn), push into heap
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int N = arr.size();
        unordered_map<int, int> m;
        for (auto num:arr)
            m[num] += 1;
        
        priority_queue<pair<int, int>> q;
        for (auto p:m)
            q.push(make_pair(p.second, p.first));
        int cur = N, res = 0;
        while (cur > N/2){
            pair<int,int> p = q.top();
            q.pop();
            int val = p.second, num = p.first;
            cur -= num;
            res += 1;
            
        }
        return res;
    }
};