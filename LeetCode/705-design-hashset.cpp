///////////////////////////////////////////////////////////////////////////////////////////////
// not easy, I just used a standard method: Open addressing
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class MyHashSet {
public:
    int N = 30003;
    int null = 0x3f3f3f3f;
    vector<int> v;
    MyHashSet() {
        for (int i=0 ; i<N ; i++) v.push_back(null);
    }
    
    int location(int key){
        int k = (key % N + N) % N;
        while (v[k] != null and v[k] != key)
            if (++k == N) k = 0;
        return k;
    }
    
    void add(int key) {
        v[location(key)] = key;
    }
    
    void remove(int key) {
        v[location(key)] = null;
    }
    
    bool contains(int key) {
        return v[location(key)]==null?false:true;
    }
};