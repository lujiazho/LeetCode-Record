///////////////////////////////////////////////////////////////////////////////////////////////
// dfs + state store with hash
////////////////
// Time Complexity: O(n^sqrt(n)), this is just an estimation of impossible worse complexity (or upper bound)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> v;
    map<pair<int, int>, bool> m;
    int v_size;
    bool winnerSquareGame(int n) {
        for (int i=1 ; i*i<=n ; i++)
            v.push_back(i*i);
        v_size = v.size();
        m.insert(pair<pair<int,int>, bool>(pair<int,int>(1,0), false));
        m.insert(pair<pair<int,int>, bool>(pair<int,int>(2,0), true));
        int flag = 0;
        for (int i=v_size-1 ; i>=0 ; i--)
            if (v[i] <= n){
                flag |= dfs(2, n-v[i]);
                if (flag) break;
            }
        return flag;
    }
    bool dfs(int who, int n){
        auto get = m.find(pair<int,int>(who, n));
        if (get != m.end())
            return m[pair<int,int>(who, n)];
        if (who == 1){ // alice
            bool flag = false;
            for (int i=v_size-1 ; i>=0 ; i--)
                if (v[i] <= n){
                    flag |= dfs(2, n-v[i]);
                    if (flag) break;
                }
            m.insert(pair<pair<int,int>, bool>(pair<int,int>(who, n), flag));
            return flag;
        }else{ // bob
            bool flag = true;
            for (int i=v_size-1 ; i>=0 ; i--)
                if (v[i] <= n){
                    flag &= dfs(1, n-v[i]);
                    if (!flag) break;
                }
            m.insert(pair<pair<int,int>, bool>(pair<int,int>(who, n), flag));
            return flag;
        }
    }
};