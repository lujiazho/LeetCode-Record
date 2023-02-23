///////////////////////////////////////////////////////////////////////////////////////////////
// hard description but easy solution
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        // sort with needed capital
        sort(projects.begin(), projects.end());
        int i = 0;
        // only store the project's profit that we can launch
        priority_queue<int> maximizeCapital;
        while (k--) {
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }
            // no project to launch
            if (maximizeCapital.empty()) break;
            // we don't need to remove launch capital
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return w;
    }
};