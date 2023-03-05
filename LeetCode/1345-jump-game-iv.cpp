///////////////////////////////////////////////////////////////////////////////////////////////
// this bfs is so slow, TLE
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
    
public:
    int minJumps(vector<int>& arr) {
        const int len = arr.size();
        unordered_map<int, unordered_set<int>> repetition; // num:[idx1,idx2]
        for (int i=0 ; i < len ; i++){
            auto get = repetition.find(arr[i]);
            if (get != repetition.end()){
                repetition[arr[i]].insert(i);
            }else{
                repetition.insert(pair<int, unordered_set<int>>(arr[i], unordered_set<int>({i})));
            }
        }
        int walked[len + 6]; // -1 means not walked
        memset(walked, -1, (len+6)*sizeof(int));
        pair<int, int> queue[len+6]; // bfs idx:step
        int hh = -1, tt = 1;
        queue[0] = pair<int,int>(0,0);
        walked[0] = 1;
        
        pair<int, int> cur;
        int loc, step;
        while (tt - hh > 1){
            hh += 1;
            cur = queue[hh];
            loc = cur.first, step = cur.second;
            if (loc == len-1)
                break;
            if (loc > 0 && walked[loc-1] == -1){
                queue[tt++] = pair<int,int>(loc-1, step+1);
                walked[loc-1] = 1;
            }
            if (loc < len-1 && walked[loc+1] == -1){
                queue[tt++] = pair<int,int>(loc+1, step+1);
                walked[loc+1] = 1;
            }
            for (auto j:repetition[arr[loc]])
                if (walked[j] == -1 && loc != j){
                    queue[tt++] = pair<int,int>(j, step+1);
                    walked[j] = 1;
                }
            repetition[arr[loc]].clear(); // so next time wouldn't enter the same group with same number
        }
        return step;
    }
};
