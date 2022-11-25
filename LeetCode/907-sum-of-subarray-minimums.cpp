///////////////////////////////////////////////////////////////////////////////////////////////
// hard, because there is duplicates in arr
// so we use not-strict increase for left, but strict incrase for right; then we can avoid duplicate computation
// or we can strict for left and non-strict for right as well, it's the same
// by the way, the basic idea behind this is that we find how many sub-arrays a value could appear in 
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int n = arr.size();
        
        // for every i find the Next smaller element to left and right
        vector<int> left(n,-1), right(n,n);
        
        // monotonic increase stack from left to right
        stack<int> st;
        for (int i=0 ; i<n ; i++) {
            // pop larger value
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            
            // find the one that is less than arr[i] in the left
            // store the distance to left vector
            if(st.size()) left[i] = i - st.top();
            // this is like i - (-1), because all is larger than arr[i]
            else left[i] = i+1;
            
            // push this value
            st.push(i);
        }
        // clear stack
        while(st.size()) st.pop();
        
        // Right
        for (int i=n-1 ; i>=0 ; i--) {
            // here it's strictly increase stack
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            // also store the distance
            if(st.size()) right[i] = st.top() - i;
            // this is straight forward, n - i where n is not a valid index
            else right[i] = n - i;
            
            st.push(i);
        }
        
        int res = 0;
        // for each arr[i], we have its in-charge area
        for (int i=0 ; i<n ; i++)
        {
            // this is in-charge of areas' number, kind of mathematic
            long long prod = (left[i]*right[i])%MOD;
            // for these areas we just use the value of arr[i]
            prod = (prod*arr[i])%MOD;
            // add it
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
};