///////////////////////////////////////////////////////////////////////////////////////////////
// hard
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto num : target){
            pq.push(num);
            sum+=num;
        }
        while(pq.top() != 1){
            int x = pq.top();
            sum -= x;
            pq.pop();
            
            // rest values cannot be equal to 0, and largest num must be > rest
            if(sum == 0 || sum >= x) return false;
            int prex = x%sum;
            // if prex == 0, two cases: 
            // 1: rest == 1, then it's ok (this happens when len(target) == 2)
            // 2: rest != 1, then it's not possible to get an all 1's array, return false
            if(sum != 1 && prex == 0) return false;
            
            pq.push(prex);
            sum += prex;
        }
        return true;
    }
};