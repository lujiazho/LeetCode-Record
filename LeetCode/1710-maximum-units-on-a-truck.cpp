///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(logn)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        return v1[1]>v2[1]?true:false;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        int res = 0;
        for (int i=0 ; i<boxTypes.size() ; i++){
            if (truckSize > 0){
                if (boxTypes[i][0] <= truckSize)
                    res += boxTypes[i][0]*boxTypes[i][1];
                else
                    res += truckSize*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }else
                break;
        }
        return res;
    }
};