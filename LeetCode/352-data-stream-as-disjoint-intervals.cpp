///////////////////////////////////////////////////////////////////////////////////////////////
// easy interval merge
////////////////
// Time Complexity: O(num*n), num is invoking times, n is count of number
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class SummaryRanges {
public:
    set<int> data; // ordered number
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        data.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        int start = -1;
        int end = -1;
        for ( auto  &item: data) {
            if (start == -1) {
                start = item;
                end = item;
            } else if (item == end + 1) {
                end = item;
            } else {
                res.push_back({start, end});
                start = end = item;
            }
        }
        if (start != -1) res.push_back({start, end});
        
        return res;
    }
};