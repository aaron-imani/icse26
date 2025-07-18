def is_even_string(s):
    mid = len(s) // 2
    return s[:mid] == s[mid:]

def main():
    S = input().strip()

    if len(S) % 2 == 1:
        S = S[:-1]
    else:
        S = S[:-2]

    while S and not is_even_string(S):
        S = S[:-2]

    print(len(S))

if __name__ == "__main__":
    main()
# End of Code
