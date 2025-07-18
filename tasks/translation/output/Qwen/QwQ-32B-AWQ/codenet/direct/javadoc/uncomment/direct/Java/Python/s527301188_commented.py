import sys

def main():
    tokens = sys.stdin.readline().split()
    stack = []
    for token in tokens:
        c = token[0]
        if c in {'+', '-', '*'}:
            b = stack.pop()
            a = stack.pop()
            if c == '+':
                stack.append(a + b)
            elif c == '-':
                stack.append(a - b)
            else:
                stack.append(a * b)
        else:
            stack.append(int(token))
    print(stack[0])

if __name__ == "__main__":
    main()
# End of Code
