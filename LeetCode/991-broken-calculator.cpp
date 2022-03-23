///////////////////////////////////////////////////////////////////////////////////////////////
// bfs time limit exceed
////////////////
// Time Complexity: O(2^32)
// Space Complexity: O(2^32)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue == target) return 0;
        
        int res = 0;
        vector<int> v;
        unordered_set<int> s;
        v.push_back(startValue);
        s.insert(startValue);
        while (true){
            vector<int> new_v;
            for (int i=0 ; i<v.size() ; i++){
                if (v[i] > target) {
                    if (s.find(v[i]-1) == s.end()) {
                        new_v.push_back(v[i]-1);
                        s.insert(v[i]-1);
                    }
                }
                else if (v[i] == target) return res;
                else{
                    if (s.find(v[i]*2) == s.end()) {
                        new_v.push_back(v[i]*2);
                        s.insert(v[i]*2);
                    }
                    if (s.find(v[i]-1) == s.end()) {
                        new_v.push_back(v[i]-1);
                        s.insert(v[i]-1);
                    }
                }
            }
            v = new_v;
            res++;
        }
        return -1;
    }
};

// this is quite simple and completely avoid dealing with big number
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        // from target to startValue
        while (target > startValue){
            if (target % 2) target ++;
            else target/=2;
            res ++;
        }
        return res + startValue - target;
    }
};