///////////////////////////////////////////////////////////////////////////////////////////////
// TLE even with hash map
////////////////
// Time Complexity: O(n^3)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> m; // val: [idx1, idx2, ...]
        for (int i=0 ; i<nums2.size() ; i++){
            m[nums2[i]].push_back(i);
        }
        
        int res = 0;
        for (int i=0 ; i<nums1.size() ; i++){
            if (m.find(nums1[i]) != m.end()){
                for (int j=0 ; j<m[nums1[i]].size() ; j++){
                    int idx = m[nums1[i]][j], k=i; // k starts from ith of nums1, idx starts from m[nums1[i]][j] of nums2
                    int cur = 0;
                    while (k < nums1.size() && idx < nums2.size() && nums1[k] == nums2[idx]) {
                        k ++;
                        idx ++;
                        cur ++;
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
};

// better solution figured by myself
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int i=0 ; i<nums1.size() ; i++){
            vector<int> roll(nums1.begin() + i, nums1.end());
            roll.insert(roll.end(), nums1.begin(), nums1.begin() + i);
            int cur = 0;
            for (int j=0 ; j<nums2.size() ; j++) {
                if (roll[j] == nums2[j]) {
                    if (j == nums1.size() - i) cur = 0; // the split, because they are not continuous actually
                    cur += 1;
                    res = max(res, cur);
                } else {
                    cur = 0;
                }
            }
        }
        return res;
    }
};