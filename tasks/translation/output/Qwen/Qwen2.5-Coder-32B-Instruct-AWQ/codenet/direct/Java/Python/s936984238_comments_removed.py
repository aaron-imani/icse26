import sys

def main():
    while read():
        solve()

def read():
    global number, score
    line = sys.stdin.readline().strip()
    if not line:
        return False
    number = int(line)
    if number == 0:
        return False
    score = list(map(int, sys.stdin.readline().strip().split()))
    return True

def solve():
    score.sort()
    total = sum(score[1:-1])
    print(total // (number - 2))

if __name__ == "__main__":
    main()
# End of Code
