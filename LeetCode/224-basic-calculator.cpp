///////////////////////////////////////////////////////////////////////////////////////////////
// hard, it turns out that my previous python solution has bugs but didn't been tested out last time
////////////////
// Time Complexity: O(n)
// Space Complexity: O(n)
///////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> stack_num;
    vector<char> stack_op;
    // 栈内优先级, '_' means negative
    unordered_map<char, int> priority = {{'(',0},{'+',1},{'-',1},{'_',2}};
    void eval_(){
        char op = stack_op.back();
        stack_op.pop_back();
        // not negative
        if (op != '_') {
            int x1 = stack_num.back();
            stack_num.pop_back();
            int x2 = stack_num.back();
            stack_num.pop_back();
            
            stack_num.push_back(op == '+'? x1 + x2 : x2 - x1);
        }
        // negative
        else {
            int x = stack_num.back();
            stack_num.pop_back();
            stack_num.push_back(-x);
        }
    }
    int calculate(string s) {
        char last_sign = ' ';
        for (int i=0 ; i<s.length() ; i++) {
            if (s[i] >= '0') {
                int num = 0;
                while (i<s.length() && s[i] >= '0') 
                    num = num*10 + (s[i++] - '0');
                stack_num.push_back(num);
                i --;
            }
            else if (s[i] == '(') {
                stack_op.push_back(s[i]);
            }
            else if (s[i] == ')') {
                // consume
                while (stack_op.back() != '(') eval_();
                // 弹出左括号
                stack_op.pop_back();
            }
            else if (s[i] == '+' || s[i] == '-') {
                if (stack_op.size() && priority[stack_op.back()] >= priority[s[i]]) {
                    eval_();
                }
                stack_op.push_back((s[i] == '-' && (last_sign == '(' || i==0)) ? '_' : s[i]);
                
            }
            if (s[i] != ' ') last_sign = s[i];
        }
        
        // consume left operations
        while (stack_op.size() > 0) eval_();
        
        return stack_num.back();
    }
};