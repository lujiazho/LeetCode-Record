///////////////////////////////////////////////////////////////////////////////////////////////
// time limit exceed
////////////////
// Time Complexity: O(n^3)
// Space Complexity: O(n^3)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> s;
        for (int i=0 ; i<nums1.size() ; i++)
            for (int j=0 ; j<nums2.size() ; j++)
                for (int k=0 ; k<nums3.size() ; k++)
                    s[nums1[i]+nums2[j]+nums3[k]] += 1;
        int res = 0;
        for (int l=0 ; l<nums4.size() ; l++){
            auto get = s.find(-nums4[l]);
            if (get != s.end()) res += s[-nums4[l]];
        }
        return res;
    }
};

// change to two 2-level loops
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> s;
        for (int i=0 ; i<nums1.size() ; i++)
            for (int j=0 ; j<nums2.size() ; j++)
                s[nums1[i]+nums2[j]] += 1;
        int res = 0;
        for (int l=0 ; l<nums4.size() ; l++){
            for (int k=0 ; k<nums3.size() ; k++){
                auto get = s.find(-nums4[l]-nums3[k]);
                if (get != s.end()) res += s[-nums4[l]-nums3[k]];
            }
        }
        return res;
    }
};