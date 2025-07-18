def is_even_string(s):
    a = s[:len(s)//2]
    b = s[len(s)//2:]
    return a == b

def main():
    s = input().strip()
    
    if len(s) % 2 == 1:
        s = s[:-1]
    else:
        s = s[:-2]

    while len(s) > 0:
        if is_even_string(s):
            break
        s = s[:-2]

    print(len(s))

if __name__ == "__main__":
    main()  # End of Code
