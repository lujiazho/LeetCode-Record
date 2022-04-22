///////////////////////////////////////////////////////////////////////////////////////////////
// just as hashset, I substitute int with pair
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyHashMap {
public:
    int null = 0x3f3f3f3f;
    int N = 100003;
    vector<pair<int,int>> v;
    MyHashMap() {
        for (int i=0 ; i<N ; i++) v.push_back(pair<int,int>(null,-1));
    }
    
    int getLoc(int key){
        int loc = (key % N + N) % N;
        while (v[loc].first != null && v[loc].first != key)
            if (++loc == N) loc = 0;
        return loc;
    }
    
    void put(int key, int value) {
        int loc = getLoc(key);
        v[loc].first = key;
        v[loc].second = value;
    }
    
    int get(int key) {
        int loc = getLoc(key);
        if (v[loc].first == key)
            return v[loc].second;
        return -1;
    }
    
    void remove(int key) {
        int loc = getLoc(key);
        v[loc].first = null;
        v[loc].second = -1;
    }
};