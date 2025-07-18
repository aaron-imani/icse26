import sys

tokens = sys.stdin.readline().split()
stack = []
for t in tokens:
    if t in '+*-':
        b = stack.pop()
        a = stack.pop()
        if t == '+':
            stack.append(a + b)
        elif t == '-':
            stack.append(a - b)
        else:
            stack.append(a * b)
    else:
        stack.append(int(t))
print(stack[0])
# End of Code
