///////////////////////////////////////////////////////////////////////////////////////////////
// half brute force, with a little optimization of recording potential start points
////////////////
// Time Complexity: O(n^2), this is the worse situation
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int sum_diff = 0;
        vector<int> pot_s; // record potential start point
        int cur_idx = -1;
        for (int i=0 ; i<gas.size() ; i++){
            int di = gas[i]-cost[i];
            diff.push_back(di);
            sum_diff += di;
            if (di < 0)
                cur_idx = -1;
            else
                if (cur_idx == -1){
                    cur_idx = i;
                    pot_s.push_back(i);
                }
        }
        if (sum_diff < 0) return -1; // if this < 0, we can never travel around
        for (int i=0 ; i<pot_s.size() ; i++){ // start from pot_s[i]
            int acc = 0, flag = 1;
            for (int j=pot_s[i] ; j<gas.size() ; j++){
                acc += diff[j];
                if (acc < 0){
                    flag = 0;
                    break;
                }
            }
            if (flag)
                for (int j=0 ; j<pot_s[i] ; j++){
                    acc += diff[j];
                    if (acc < 0){
                        flag = 0;
                        break;
                    }
                }
            if (flag) return pot_s[i];
        }
        return -1;
    }
};

// this is a theoretical O(n) time complexity, but the actual time is not really better than the one above
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum_diff = 0;
        int cur_idx = -1;
        int cur_sum = 0;
        for (int i=0 ; i<gas.size() ; i++){
            int di = gas[i]-cost[i];
            sum_diff += di;
            if ((cur_sum + di) < 0){ // only when acc < 0, we restart
                cur_idx = -1;
                cur_sum = 0;
            }
            else{
                if (cur_idx == -1) cur_idx = i;
                cur_sum += di;
            }
        }
        if (sum_diff < 0) return -1; // if this < 0, we can never travel around
        return cur_idx;
    }
};
