///////////////////////////////////////////////////////////////////////////////////////////////
// kind of like dp, but the case is less, so just need to traverse 4 times
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int N = tops.size();
        int res = N+1;
        // change top to top[0]
        int cur = 0;
        for (int i=1 ; i<N ; i++){
            if (tops[i] != tops[0]){
                if (bottoms[i] != tops[0]){
                    cur = N+1;
                    break;
                }else{
                    cur += 1;
                }
            }
        }
        res = min(res, cur);
        // change bottom to top[0]
        cur = 1;
        for (int i=1 ; i<N ; i++){
            if (bottoms[i] != tops[0]){
                if (tops[i] != tops[0]){
                    cur = N+1;
                    break;
                }else{
                    cur += 1;
                }
            }
        }
        res = min(res, cur);
        // change top to bottom[0]
        cur = 1;
        for (int i=1 ; i<N ; i++){
            if (tops[i] != bottoms[0]){
                if (bottoms[i] != bottoms[0]){
                    cur = N+1;
                    break;
                }else{
                    cur += 1;
                }
            }
        }
        res = min(res, cur);
        // change bottom to bottom[0]
        cur = 0;
        for (int i=1 ; i<N ; i++){
            if (bottoms[i] != bottoms[0]){
                if (tops[i] != bottoms[0]){
                    cur = N+1;
                    break;
                }else{
                    cur += 1;
                }
            }
        }
        res = min(res, cur);
        return res==N+1?-1:res;
    }
};