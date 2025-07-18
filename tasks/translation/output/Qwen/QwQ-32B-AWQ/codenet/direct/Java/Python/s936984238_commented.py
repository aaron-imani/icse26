import sys

def read():
    global number, score
    number = int(sys.stdin.readline())
    if number == 0:
        return False
    score = list(map(int, sys.stdin.readline().split()))
    return True

def slove():
    global number, score
    score.sort()
    sum_val = sum(score[1:-1])
    avg = sum_val // (number - 2)
    print(avg)

def main():
    while read():
        slove()

if __name__ == "__main__":
    main()
# End of Code
