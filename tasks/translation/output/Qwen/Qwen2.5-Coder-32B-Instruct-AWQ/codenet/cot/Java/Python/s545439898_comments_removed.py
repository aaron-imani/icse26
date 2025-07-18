import sys

def main():
    count = int(input())
    giving_numbers = [int(input()) for _ in range(count)]

    for i in range(count - 1, -1, -1):
        print(giving_numbers[i], end='')
        if i > 0:
            print(' ', end='')
    print()

if __name__ == "__main__":
    main()
# End of Code
