###############################################################################################
# 某种程度上比ACwing的那道题简单，因为没有*、/法，但多了一个单目运算符和空格
###########
# 时间复杂度：O(n)
# 空间复杂度：O(n)，存放num和op的数组开销总和
###############################################################################################
class Solution:
    def calculate(self, s: str) -> int:
        stack_num = []
        stack_op = []
        
        priority = {'(':0,'+':1,'-':1,'--':2} # 栈内优先级, '--'表示单目减号
        
        def eval_():
            op = stack_op.pop()
            if op != '--':
                x1, x2 = stack_num.pop(), stack_num.pop()
                stack_num.append(x1 + x2 if op == '+' else x2 - x1)
            else:
                x = stack_num.pop()
                stack_num.append(-x)

        i = 0
        while i < len(s):
            if s[i].isdigit():
                num = 0
                while i<len(s) and s[i].isdigit():
                    num = num*10 + int(s[i])
                    i += 1
                stack_num.append(num)
                i -= 1
            elif s[i] == '(':
                stack_op.append(s[i])
            elif s[i] == ')':
                while stack_op[-1] != '(':
                    eval_()
                stack_op.pop() # 弹出左括号
            elif s[i] == '+' or s[i] == '-':
                if len(stack_op) and priority[stack_op[-1]] >= priority[s[i]]:
                    eval_()
                stack_op.append('--' if s[i] == '-' and (s[i-1] == '(' or not i) else s[i]) # 处理单目
            i += 1
        while len(stack_op):
            eval_()
        return stack_num[-1]