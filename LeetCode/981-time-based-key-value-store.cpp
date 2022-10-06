///////////////////////////////////////////////////////////////////////////////////////////////
// just need to find a easy way to do it in c++
////////////////
// Time Complexity: O(logn), for get
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class TimeMap {
    unordered_map<string, map<int, string>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        auto it = m[key].upper_bound(timestamp);
        // upper bound always leads to the pointer after the value we want
        // so it points to begin only when there is no value available
        if (it == m[key].begin()) return "";
        return prev(it)->second;
    }
};