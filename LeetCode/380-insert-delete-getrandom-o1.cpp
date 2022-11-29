///////////////////////////////////////////////////////////////////////////////////////////////
// just use rand() function in c++ and map for quick search and vector for random pick
////////////////
// Time Complexity: O(1)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> m;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        // already exist
        if (m.find(val) != m.end()) return false;
        
        nums.push_back(val);
        // mark the location in vector for delete
        m[val] = nums.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        // not exist
        if (m.find(val) == m.end()) return false;
        
        // save the last number to the position of the removed one
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        // pop the last one
        nums.pop_back();
        // erase from map
        m.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};