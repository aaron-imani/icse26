def main():
    tokens = input().split()
    stack = []
    for token in tokens:
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
if __name__ == "__main__":
    main()
# End of Code
