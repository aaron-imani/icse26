import sys

def main():
    try:
        s = input().split()
        a = int(s[0])
        b = int(s[1])
        if b % a == 0:
            print(a + b)
        else:
            print(b - a)
    except Exception as e:
        print(e)

if __name__ == "__main__":
    main()
# End of Code
