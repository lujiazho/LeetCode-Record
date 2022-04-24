///////////////////////////////////////////////////////////////////////////////////////////////
// cool, I found a way to use pair as unordered_map key
// Also, pair could be used as value without limitation
////////////////
// Time Complexity: O(1)
// Space Complexity: O(n), depends on locations' number
///////////////////////////////////////////////////////////////////////////////////////////////
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;             
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> id2start;
    unordered_map<pair<string, string>, pair<int,int>, hash_pair> time;
    UndergroundSystem() {
        return;
    }
    
    void checkIn(int id, string stationName, int t) {
        id2start[id].first = stationName;
        id2start[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        time[pair<string, string>(id2start[id].first, stationName)].first += t - id2start[id].second;
        time[pair<string, string>(id2start[id].first, stationName)].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int,int> info = time[pair<string,string>(startStation,endStation)];
        return 1.0 * info.first / info.second;
    }
};