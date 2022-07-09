///////////////////////////////////////////////////////////////////////////////////////////////
// not easy, but it becomes clear if start from back to front
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n=nums.size();
        int score[n]; // max scores if starting from i to n-1
        priority_queue<pair<int, int>> pq;
        
        // from back to front
        for(int i=n-1 ; i>=0 ; i--)
        {
            while(pq.size() && pq.top().second>i+k)
                pq.pop(); // pop the values that are out of the window of current idx
            
            score[i] = nums[i]; // starting score
            score[i] += (pq.size() ? pq.top().first : 0); // add max score within window
            
            pq.push({score[i], i});
        }
        
        return score[0];
    }
};