///////////////////////////////////////////////////////////////////////////////////////////////
// easy algorithm but complex implementation
////////////////
// Time Complexity: O(1)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class LFUCache {
public:
    int capacity;
    int minFreq;
    // key 2 {value, used_count}
    unordered_map<int, pair<int,int>> keyVal;
    // frequency 2 key
    unordered_map<int, list<int>> freqList;
    // key 2 position (directly point to the position in freqList)
    unordered_map<int, list<int>::iterator> pos;
    LFUCache(int capa) {
        capacity = capa;
        minFreq = 0;
    }
    
    int get(int key) {
        // not exist
        if(keyVal.find(key) == keyVal.end()) return -1;

        // remove from original place
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++; // adding used_count
        freqList[keyVal[key].second].push_back(key); // put to the end
        pos[key] = --freqList[keyVal[key].second].end(); // update position pointer

        if(freqList[minFreq].empty()) minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity) return;

        // if key already exist
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value; // change value
            freqList[keyVal[key].second].erase(pos[key]); // remove from original position
            keyVal[key].second++; // still accumulating count
            freqList[keyVal[key].second].push_back(key); // add to the end
            pos[key] = --freqList[keyVal[key].second].end(); // record the position
            if(freqList[minFreq].empty()) minFreq++;
            return;
        }

        // pop the LFU
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        // put in
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};