///////////////////////////////////////////////////////////////////////////////////////////////
// n^2*logn still exceed the time limit
////////////////
// Time Complexity: O(n^2*logn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, vector<int>> m;
        for (int i=0 ; i<arr.size() ; i++){
            m[arr[i]].push_back(i);
        }
        int res = 0;
        for (int i=0 ; i<arr.size() ; i++){
            for (int j=i+1 ; j<arr.size() ; j++){
                int knum = target-arr[i]-arr[j];
                if (m.find(knum) != m.end()){
                    int st=0, ed=m[knum].size()-1, mid;
                    while (st < ed){
                        mid = (st+ed)>>1;
                        if (m[knum][mid] <= j)
                            st = mid+1;
                        else
                            ed = mid;
                    }
                    if (m[knum][ed] > j){
                        res += m[knum].size() - ed;
                    }
                }
            }
        }
        return res;
    }
};

// other's method, more useful before it take i as k at first so it will keep the order
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int, int> m;
        int res = 0, mod=1e9+7;
        for (int i=0 ; i<arr.size() ; i++){
            // consider this i as k before it added with j
            res = (res + m[target-arr[i]])%mod;
            for (int j=0 ; j<i ; j++){
                m[arr[i]+arr[j]]++;
            }
        }
        return res;
    }
};