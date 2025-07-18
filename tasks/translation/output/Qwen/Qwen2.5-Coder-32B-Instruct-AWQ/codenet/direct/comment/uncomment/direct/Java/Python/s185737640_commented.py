def is_even_string(s):
    a = s[:len(s)//2]
    b = s[len(s)//2:]
    return a == b

def main():
    import sys
    input = sys.stdin.read().strip()
    
    if len(input) % 2 == 1:
        input = input[:-1]
    else:
        input = input[:-2]
    
    while len(input) > 0:
        if is_even_string(input):
            break
        input = input[:-2]
    
    print(len(input))

if __name__ == "__main__":
    main()
# End of Code
