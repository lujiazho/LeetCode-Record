///////////////////////////////////////////////////////////////////////////////////////////////
// time exceed
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class FreqStack {
public:
    unordered_map<int,int> m;
    vector<int> v;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val] += 1;
        v.push_back(val);
    }
    
    int pop() {
        unordered_set<int> max_;
        int max_f = 0;
        for (auto per:m){
            if (per.second > max_f){
                max_.clear();
                max_.insert(per.first);
                max_f = per.second;
            }else if(per.second == max_f){
                max_.insert(per.first);
            }
        }
        int idx = -1;
        for (int i=v.size()-1 ; i>=0 ; i--){
            if (max_.find(v[i]) != max_.end()){
                idx = i;
                break;
            }
        }
        int res = v[idx];
        m[v[idx]] -= 1;
        for (int j=idx ; j<v.size()-1 ; j++){
            v[j] = v[j+1];
        }
        v.pop_back();
        return res;
    }
};

// other's way, use freq2val to help find the val with largest freq quickly
// Besides, use vector in map to avoid creating another vector to store
class FreqStack {
public:
    unordered_map<int,int> val2freq; // val 2 freq
    unordered_map<int,vector<int>> freq2val; // freq 2 val
    int max_f;
    FreqStack() {
        max_f = -1;
    }
    
    void push(int val) {
        // note: we cannot delete some value with freq k in freq2val[k], because this store the order
        val2freq[val] += 1;
        freq2val[val2freq[val]].push_back(val);
        if (val2freq[val] > max_f) max_f = val2freq[val];
    }
    
    int pop() {
        int res = freq2val[max_f].back();
        freq2val[max_f].pop_back();
        val2freq[res] --;
        if (!freq2val[max_f].size()) max_f --;
        return res;
    }
};