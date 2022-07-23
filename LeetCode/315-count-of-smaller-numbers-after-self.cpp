///////////////////////////////////////////////////////////////////////////////////////////////
// not easy to think of using merge sort to solve it
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    void mergeSort(vector<int>& arr, int l, int r,vector<pair<int,int>>& v,vector<int>& count)
    {
        if (l >= r) return;
        int mid = (l+r)>>1;
        mergeSort(arr, l, mid, v, count);
        mergeSort(arr, mid+1, r, v, count);
        
        // merge two sorted list (large to small)
        vector<pair<int,int>> temp(r-l+1);
        int i = l, j = mid+1, k = 0;
        
        while(i<=mid && j<=r){
            // who's large, put it at front
            if(v[i].first > v[j].first) {
                // here is critical: v[i] is larger than v[j] and all nums after it
                count[v[i].second] += r-j+1;
                temp[k++] = v[i++];
            }else
                temp[k++] = v[j++];
        }
        
        while (i <= mid) temp[k++] = v[i++];
        while (j <= r) temp[k++] = v[j++];
        for(int i=l ; i<=r ; i++) v[i] = temp[i-l];
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        
        // for quick indexing. num:idx
        vector<pair<int,int>> v;
        for(int i=0 ; i<n ; i++) v.push_back({nums[i],i});
        
        mergeSort(nums, 0, n-1, v, res);
        
        return res;
    }
};