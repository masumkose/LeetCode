from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []

        for t in tokens:
            if t == '+':
                a, b = stack.pop(), stack.pop()
                stack.append(a + b)
            elif t == '*':
                a, b = stack.pop(), stack.pop()
                stack.append(a * b)
            elif t == '-':
                a, b = stack.pop(), stack.pop()
                stack.append(b - a)
            elif t == '/':
                a, b = stack.pop(), stack.pop()
                stack.append(int(float(b) / a))
            else:
                stack.append(int(t))

        return stack.pop()



ss = Solution()


tokens = [  ["2","1","+","3","*"],
            ["4","13","5","/","+"],
            ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]]

for tok in tokens:
    print(ss.evalRPN(tok))