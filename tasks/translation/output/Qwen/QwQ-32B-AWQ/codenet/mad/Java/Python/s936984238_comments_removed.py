def read():
    global number, score
    number = int(input())
    if number == 0:
        return False
    score = list(map(int, input().split()))
    return True

def solve():
    global number, score
    score.sort()
    total = sum(score[1:-1])
    divisor = number - 2
    if divisor == 0:
        print(0)
        return
    quotient = total // divisor
    rem = total % divisor
    if rem != 0 and ((total < 0) ^ (divisor < 0)):
        quotient += 1
    print(quotient)

number = 0
score = []
while read():
    solve()
# End of Code
