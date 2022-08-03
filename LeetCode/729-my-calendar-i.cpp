///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyCalendar {
public:
    vector<pair<int, int>> v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (int i=0 ; i<v.size() ; i++){
            if ((v[i].first <= start && start < v[i].second) || 
                (v[i].first < end && end <= v[i].second) || 
                (start <= v[i].first && v[i].first < end) || 
                (start < v[i].second && v[i].second <= end))
                return false;
        }
        v.push_back({start, end});
        return true;
    }
};