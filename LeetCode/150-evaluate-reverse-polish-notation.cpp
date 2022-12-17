///////////////////////////////////////////////////////////////////////////////////////////////
// easy
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<long long int> v;

        for (int i=0 ; i<tokens.size() ; i++) {
            string s = tokens[i];
            long long int cur = 0;
            if ((s.length() <= 1) && (s[0] == '+' || s[0] == '*' || s[0] == '/' || s[0] == '-')) {
                long long int a2 = v.back();
                v.pop_back();
                long long int a1 = v.back();
                v.pop_back();
                switch (s[0]) {
                    case '+': cur = a1 + a2; break;
                    case '*': cur = a1 * a2; break;
                    case '/': cur = a1 / a2; break;
                    case '-': cur = a1 - a2; break;
                }
                v.push_back(cur);
            } else {
                cur = stoi(tokens[i]);
                v.push_back(cur);
            }
        }
        return v.back();
    }
};