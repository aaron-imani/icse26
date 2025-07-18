import sys

strs = sys.stdin.readline().split()
stack = []
for s in strs:
    if s in '+-*/':
        b = stack.pop()
        a = stack.pop()
        if s == '+':
            stack.append(a + b)
        elif s == '-':
            stack.append(a - b)
        elif s == '*':
            stack.append(a * b)
    else:
        stack.append(int(s))
print(stack[0])
# End of Code
