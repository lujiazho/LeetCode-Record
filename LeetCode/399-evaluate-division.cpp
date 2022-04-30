///////////////////////////////////////////////////////////////////////////////////////////////
// no points
////////////////
// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> m;
        for (int i=0 ; i<equations.size() ; i++){
            m[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            m[equations[i][1]].push_back(make_pair(equations[i][0], 1.0/values[i]));
            // for equations[i][0]
            for (int j=0 ; j<m[equations[i][1]].size() ; j++){
                if (m[equations[i][1]][j].first != equations[i][0]){
                    m[equations[i][0]].push_back(make_pair(m[equations[i][1]][j].first, values[i]*m[equations[i][1]][j].second));
                    m[m[equations[i][1]][j].first].push_back(make_pair(equations[i][0], 1.0/(values[i]*m[equations[i][1]][j].second)));
                }
            }
            // for equations[i][1]
            for (int j=0 ; j<m[equations[i][0]].size() ; j++){
                if (m[equations[i][0]][j].first != equations[i][1]){
                    m[equations[i][1]].push_back(make_pair(m[equations[i][0]][j].first, (1.0/values[i])*m[equations[i][0]][j].second));
                    m[m[equations[i][0]][j].first].push_back(make_pair(equations[i][1], 1.0*values[i]/m[equations[i][0]][j].second));
                }
            }
        }
        
        vector<double> res;
        for (int i=0 ; i<queries.size() ; i++){
            // search again
            vector<pair<string,double>> points(m[queries[i][0]].begin(), m[queries[i][0]].end());
            unordered_map<string, double> ratios;
            unordered_set<string> track;
            for (int k=0 ; k<m[queries[i][0]].size() ; k++)
                track.insert(m[queries[i][0]][k].first);
            track.insert(queries[i][0]);

            while (!points.empty()) {
                pair<string,double> x = points.back();
                points.pop_back();
                string nxt = x.first;
                double rat = x.second;

                for (int k=0 ; k<m[nxt].size() ; k++) {
                    if (track.find(m[nxt][k].first) == track.end()){
                        points.push_back(pair<string,double>(m[nxt][k].first, rat*m[nxt][k].second));
                        m[queries[i][0]].push_back(pair<string,double>(m[nxt][k].first, rat*m[nxt][k].second));
                        track.insert(m[nxt][k].first);
                    }
                }
            }
            
            if (m.find(queries[i][0]) != m.end() && m[queries[i][0]].size()){
                int flag = 0;
                for (int j=0 ; j<m[queries[i][0]].size() ; j++){
                    if (m[queries[i][0]][j].first == queries[i][1]){
                        flag = 1;
                        res.push_back(m[queries[i][0]][j].second);
                        break;
                    }
                }
                if (flag)
                    continue;
                if (queries[i][0] == queries[i][1]){
                    res.push_back(1.0);
                    continue;
                }
            }
            res.push_back(-1.0);
        }
        return res;
    }
};