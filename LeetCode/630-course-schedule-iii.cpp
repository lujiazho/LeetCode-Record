///////////////////////////////////////////////////////////////////////////////////////////////
// doesn't have enough energy for today's problem
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
bool cmp(vector<int>&a,vector<int>&b)
{
    return a[1]<b[1];
}
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int>pq;
        int timetaken = 0;
        for(auto course:courses)
        {
            if(timetaken +  course[0]<=course[1])
            {
                timetaken = timetaken + course[0];
                pq.push(course[0]);
            }
            else
            {
                if(!pq.empty() && pq.top()>course[0])
                {
                    timetaken = timetaken - pq.top();
                    pq.pop();
                    pq.push(course[0]);
                    timetaken = timetaken + course[0];
                }
            }
        }
        return pq.size();
    }
};