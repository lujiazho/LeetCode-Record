###############################################################################################
# easy
############# 
# Time Complexity: O(n)
# Space Complexity: O(n)
###############################################################################################
class Solution:
    def calculate(self, s: str) -> int:
        stack_op = []
        stack_num = []
        priority = {'+':0,'-':0,'*':1,'/':1}
        
        def eval_():
            num2, num1, num = int(stack_num.pop()), int(stack_num.pop()), 0
            op = stack_op.pop()
            if op == '+':
                num = num1 + num2
            elif op == '-':
                num = num1 - num2
            elif op == '*':
                num = num1 * num2
            else:
                num = num1 // num2
            stack_num.append(str(num))
        
        i = 0
        while i < len(s):
            if s[i].isnumeric():
                num = ''
                while i < len(s) and s[i].isnumeric():
                    num += s[i]
                    i += 1
                stack_num.append(num)
                i -= 1
            elif s[i] == ' ':
                i += 1
                continue
            else:
                op = s[i]
                while len(stack_op) and priority[stack_op[-1]] >= priority[op]:
                    eval_()
                stack_op.append(op)
            i += 1
        while stack_op:
            eval_()
        return stack_num[-1]