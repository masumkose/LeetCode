
class MinStack:

    def __init__(self):
        self.stack = []
        self.minvalues = []
    
    def push(self, val: int) ->  None:
        self.stack.append(val)
        if not self.minvalues:
            self.minvalues.append(val)
        else:
            self.minvalues.append(min(self.minvalues[-1], val))

    
    def pop(self) -> None:
        self.stack.pop()
        self.minvalues.pop()
    
    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minvalues[-1]



minstack = MinStack()

minstack.push(-2)
minstack.push(0)
minstack.push(-3)
minstack.getMin()
minstack.pop()
minstack.top()
minstack.getMin()

print(minstack.stack)