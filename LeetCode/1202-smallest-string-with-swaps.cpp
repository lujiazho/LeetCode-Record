///////////////////////////////////////////////////////////////////////////////////////////////
// not easy, it's complex even not hard
////////////////
// Time Complexity: O(nlogn)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> father;
    template <class T> struct comp{
        bool operator() (const T& x, const T& y) const {return x>y;}
    };
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for (int i=0 ; i<s.size() ; i++)
            father.push_back(i);
        for (int i=0 ; i<pairs.size() ; i++)
            connect(pairs[i][0], pairs[i][1]);

        unordered_map<int, priority_queue<char, vector<char>, comp<char>>> m;
        for (int i=0 ; i<s.length() ; i++){
            m[find(i)].push(s[i]);
        }
        string res = "";
        for (int i=0 ; i<s.length() ; i++){
            char ch = m[find(i)].top();
            m[find(i)].pop();
            res += ch;
        }
        return res;
    }
    int find(int x){
        if (father[x] != x)
            father[x] = find(father[x]);
        return father[x];
    }
    void connect(int a, int b){
        father[find(a)] = find(b);
    }
};