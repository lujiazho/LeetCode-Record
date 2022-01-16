///////////////////////////////////////////////////////////////////////////////////////////////
// we only need to calculate every space between two seats: dis
// then we get the pre-space(space before the first seat) and rear-space(space after the last seat)
// so we just return max(firstone, dis/2, len(seats)-1-j)
////////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int firstone = -1, j = 0, dis = 0, n = seats.size();
        for (int i=0 ; i<n ; i++){
            if (seats[i] == 1){
                if (firstone == -1)
                    firstone = i;
                dis = max(dis, i - j);
                j = i;
            }
        }
        return max(max(firstone, dis/2), n-1-j);
    }
};