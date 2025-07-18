import sys

def main():
    while read():
        slove()

def read():
    global number, score
    number = int(input())
    if number == 0:
        return False
    score = [int(input()) for _ in range(number)]
    return True

def slove():
    score.sort()
    sum = 0
    for i in range(1, number-1):
        sum += score[i]
    print(sum // (number - 2))

if __name__ == "__main__":
    main()  # End of Code
