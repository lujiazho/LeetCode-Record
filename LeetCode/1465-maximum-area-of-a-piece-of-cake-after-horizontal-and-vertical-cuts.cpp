///////////////////////////////////////////////////////////////////////////////////////////////
// easy way, but annoying to handle long int in C++
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int MOD = 1e9+7;
        int last = 0;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        vector<int> hor, ver;
        for (int i=0 ; i<horizontalCuts.size() ; i++){
            hor.push_back(horizontalCuts[i] - last);
            last = horizontalCuts[i];
        }
        hor.push_back(h - last);
        last = 0;
        for (int i=0 ; i<verticalCuts.size() ; i++){
            ver.push_back(verticalCuts[i] - last);
            last = verticalCuts[i];
        }
        ver.push_back(w - last);
        sort(hor.begin(), hor.end());
        sort(ver.begin(), ver.end());
        long int m = hor.back();
        long int n = ver.back();
        long long int res = m*n;
        return res%MOD;
    }
};