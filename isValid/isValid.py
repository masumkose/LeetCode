class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        if not s:
            return False
        for c in s:
            if c == ']' or c == '}' or c == ')':
                if not stack:
                    return False
                ch = stack.pop()
                if c == '}':
                    if (ch != '{'):
                        return False
                elif c == ']':
                    if (ch != '['):
                        return False
                elif c == ')':
                    if (ch != '('):
                        return False
            else:
                stack.append(c)
        if len(stack) == 0:
            return True
        else:
            return False




ss = Solution()

print(ss.isValid("()[]{}["))




