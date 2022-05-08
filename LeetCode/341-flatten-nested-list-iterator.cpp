///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class NestedIterator {
public:
    vector<int> v;
    int idx = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    void dfs(vector<NestedInteger> List){
        for (int i=0 ; i<List.size() ; i++){
            if (List[i].isInteger())
                v.push_back(List[i].getInteger());
            else
                dfs(List[i].getList());
        }
    }
    
    int next() {
        return v[idx++];
    }
    
    bool hasNext() {
        return idx<v.size();
    }
};