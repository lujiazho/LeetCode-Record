///////////////////////////////////////////////////////////////////////////////////////////////
// almost brute method but works
////////////////
// Time Complexity: O((n^2)*O(kmp)), just a simple estimation
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        
        auto total_stamp = 0, turned_stamp = -1;
        while (turned_stamp){
            turned_stamp = 0;
            
            for(int sz = stamp.size(); sz>0; --sz){
                for(auto i =0;i<=stamp.size()-sz;i++){
                    // two loops for getting all possibilities
                    auto new_stamp = string(i, '?') + stamp.substr(i, sz) + string(stamp.size() - sz - i, '?');
                    auto pos = target.find(new_stamp);
                    // string::npos: the end of the string
                    while(pos != string::npos){
                        // matched
                        res.push_back(pos);
                        turned_stamp += sz;
                        // cover with '?'
                        fill(begin(target) + pos, begin(target) + pos + stamp.size() , '?');
                        pos = target.find(new_stamp); // find again
                    }
                }
                
            }
            total_stamp += turned_stamp;
        }
        reverse(begin(res), end(res)); 
        //checking if the all the characters are convered to '?'
        return total_stamp == target.size() ? res : vector<int>();
    }
};