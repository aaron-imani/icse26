import sys

def read():
    global number, score
    number = int(sys.stdin.readline().strip())
    if number == 0:
        return False
    score = list(map(int, sys.stdin.readline().strip().split()))
    return True

def solve():
    score.sort()
    total = sum(score[1:-1])
    print(total // (number - 2))

number = 0
score = []

def main():
    while read():
        solve()

if __name__ == "__main__":
    main()
# End of Code
