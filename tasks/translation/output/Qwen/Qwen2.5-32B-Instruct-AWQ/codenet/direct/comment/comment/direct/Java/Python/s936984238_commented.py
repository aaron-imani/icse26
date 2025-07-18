import sys

def main():
    while read():
        solve()

def read():
    global number, scores
    number = int(input())
    if number == 0:
        return False
    scores = list(map(int, input().split()))
    return True

def solve():
    scores.sort()
    total_sum = sum(scores[1:-1])
    print(total_sum // (number - 2))

if __name__ == "__main__":
    main()  # End of Code
