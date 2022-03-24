///////////////////////////////////////////////////////////////////////////////////////////////
// greedy method
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end(), greater<int>());
        priority_queue<int, vector<int>> heap;
        int res = 0;
        for (int i=0 ; i<people.size() ; i++){
            if (!heap.size() || (heap.size() && people[i] > heap.top())){
                res += 1;
                heap.push(limit - people[i]);
            }else{
                heap.pop();
            }
        }
        return res;
    }
};