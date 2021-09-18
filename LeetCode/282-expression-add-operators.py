###############################################################################################
# 手写计算函数，在dfs最后一层计算，超时
###########
# 时间复杂度：O(s*n*(3^10)), s是最后exp字符串的长度，n是该层下可取数字的种类数
# 空间复杂度：O(n)，自己实现cal需要额外空间，用eval则只需要栈消耗，
###############################################################################################
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def cal(exp):
            priority = {'*':2, '+':1, '-':1}
            stack_op = []
            stack_num = []

            def eval_():
                x1, x2 = stack_num.pop(), stack_num.pop()
                op = stack_op.pop()
                stack_num.append(str(eval(x2+op+x1)))
            
            i, len_ = 0, len(exp)
            while i < len_:
                if exp[i].isdigit():
                    num =''
                    while i < len_ and exp[i].isdigit():
                        num += exp[i]
                        i += 1
                    stack_num.append(num)
                    i -= 1
                else:
                    if stack_op and priority[stack_op[-1]] >= priority[exp[i]]:
                        eval_()
                    stack_op.append(exp[i])
                i += 1
            while len(stack_op):
                eval_()
            return int(stack_num[-1])
        
        len_, res = len(num), []
        def dfs(i, exp):
            if i >= len_:
                if cal(exp) == target:
                    res.append(exp)
                return
            
            if not int(num[i]):
                dfs(i+1, exp+'+'+num[i])
                dfs(i+1, exp+'-'+num[i])
                dfs(i+1, exp+'*'+num[i])
            else:
                for j in range(i, len_):
                    dfs(j+1, exp+'+'+num[i:j+1])
                    dfs(j+1, exp+'-'+num[i:j+1])
                    dfs(j+1, exp+'*'+num[i:j+1])
        if int(num[0]):
            for j in range(len_):
                dfs(j+1, num[0:j+1])
        else:
            dfs(1, num[0])
        return res

# 去掉cal，直接换成内置eval，没有超时了，但耗时很多
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        len_, res = len(num), []
        def dfs(i, exp):
            if i >= len_:
                if eval(exp) == target:
                    res.append(exp)
                return
            
            if not int(num[i]):
                dfs(i+1, exp+'+'+num[i])
                dfs(i+1, exp+'-'+num[i])
                dfs(i+1, exp+'*'+num[i])
            else:
                for j in range(i, len_):
                    dfs(j+1, exp+'+'+num[i:j+1])
                    dfs(j+1, exp+'-'+num[i:j+1])
                    dfs(j+1, exp+'*'+num[i:j+1])
        if int(num[0]):
            for j in range(len_):
                dfs(j+1, num[0:j+1])
        else:
            dfs(1, num[0])
        return res

# 增加两个额外参数：实时记录当前exp的value以及最后一个数的value(带正负号)，这样遇到乘法时，就能直接减去last再加上乘法的部分，last也同时更新为乘法那部分
class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        len_, res = len(num), []
        # exp: current expression, value: current value, last: the last number in exp
        def dfs(i, exp, value, last):
            if i >= len_:
                if value == target:
                    res.append(exp)
                return

            for j in range(i, len_):
                if j == i or (j > i and num[i] != '0'):
                    dfs(j+1, exp+'+'+num[i:j+1], value+int(num[i:j+1]), int(num[i:j+1]))
                    dfs(j+1, exp+'-'+num[i:j+1], value-int(num[i:j+1]), -int(num[i:j+1]))
                    dfs(j+1, exp+'*'+num[i:j+1], value-last+last*int(num[i:j+1]), last*int(num[i:j+1]))
        
        for j in range(len_):
            if j == 0 or (j > 0 and num[0] != '0'):
                dfs(j+1, num[0:j+1], int(num[0:j+1]), int(num[0:j+1]))
        return res

# 常规时每层中进入dfs的次数：1 + 3 + 3 * 3
# 此算法每层中进入dfs的次数：n + 3*(0+...+n-1) + 3 * ( 0 + ... + (n-3)*(n-4) + (n-2)*(n-3) + (n-1)*(n-2) ) ≈ 3*((n-1)! + (n-2)! + (n-3)! + (n-4)! + ... + 0!)