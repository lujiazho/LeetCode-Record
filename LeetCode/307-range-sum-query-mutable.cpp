///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class NumArray {
public:
    int sum;
    int N;
    vector<int> v;
    NumArray(vector<int>& nums) {
        v = nums;
        N = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
    }
    
    void update(int index, int val) {
        sum -= v[index];
        v[index] = val;
        sum += val;
    }
    
    int sumRange(int left, int right) {
        int res = sum;
        for (int i=0 ; i<left ; i++)
            res -= v[i];
        for (int i=right+1 ; i<N ; i++)
            res -= v[i];
        return res;
    }
};