///////////////////////////////////////////////////////////////////////////////////////////////
// not hard
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
bool compare( const pair<int,string> & e1, const pair<int,string> & e2) {
    if( e1.first != e2.first) return (e1.first > e2.first);
    return (e1.second < e2.second);
}
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto s:words) m[s] += 1;
        int max_ = 0;
        vector<pair<int, string>> v;
        for (auto p:m) {
            v.push_back(make_pair(p.second, p.first));
        }
        sort(v.begin(), v.end(), compare);
        vector<string> res;
        for (int i=0 ; i<k ; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};