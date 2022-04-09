///////////////////////////////////////////////////////////////////////////////////////////////
// my first to write template for algorithm, cool, from now on I can use heap to sort pairs
////////////////
// Time Complexity: O(n), I estimate the construction of heap is O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    template <class T> struct comp{
        bool operator() (const T& x, const T& y) const {return x.second<y.second;}
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        for (int i=0 ; i<nums.size() ; i++)
            m[nums[i]]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp<pair<int,int>>> heap(m.begin(), m.end());
        vector<int> res;
        for (int i=0 ; i<k ; i++){
            res.push_back(heap.top().first);
            heap.pop();
        }
        return res;
    }
};