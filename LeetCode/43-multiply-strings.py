###############################################################################################
# use big number * small number and bignumber + bignumber to implement big number * bignumber
###########
# 时间复杂度：O(len(num1)*len(num2))
# 空间复杂度：O(len(num1)+len(num2))
###############################################################################################
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        def mul_big_small(a: list[int], b: int):
            t, c = 0, []
            for i in range(len(a)):
                t += a[i]*b
                c.append(t%10)
                t //= 10
            if t:
                c.append(t)
            while len(c) > 1 and not c[-1]:
                c.pop()
            return c
        def add_big_big(l1, l2):
            t, c = 0, []
            for i in range(max(len(l1), len(l2))):
                if i < len(l1):
                    t += l1[i]
                if i < len(l2):
                    t += l2[i]
                c.append(t%10)
                t //= 10
            if t:
                c.append(t)
            return c
        A = list(map(int, num1))[::-1]
        res = mul_big_small(A, int(num2[len(num2)-1]))
        for i in range(len(num2)-2, -1, -1):
            ret = mul_big_small(A, int(num2[i]))
            res = add_big_big(res, [0]*(len(num2)-1-i) + ret)
        while len(res) > 1 and not res[-1]:
            res.pop()
        return ''.join(map(str, res[::-1]))