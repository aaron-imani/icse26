import sys

parts = sys.stdin.readline().split()
stack = []
for token in parts:
    if token in '+-*':
        b = stack.pop()
        a = stack.pop()
        if token == '+':
            stack.append(a + b)
        elif token == '-':
            stack.append(a - b)
        elif token == '*':
            stack.append(a * b)
    else:
        stack.append(int(token))
print(stack[0])
# End of Code
