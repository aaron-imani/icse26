import sys

def read():
    number = int(input())
    if number == 0:
        return False
    score = [int(input()) for _ in range(number)]
    return score, number

def slove(score, number):
    score.sort()
    sum = 0
    for i in range(1, number - 1):
        sum += score[i]
    print(sum // (number - 2))

if __name__ == "__main__":
    while True:
        result = read()
        if not result:
            break
        score, number = result
        slove(score, number)
# End of Code
