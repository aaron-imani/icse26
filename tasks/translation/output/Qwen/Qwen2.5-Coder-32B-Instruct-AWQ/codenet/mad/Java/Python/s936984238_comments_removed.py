def main():
    while read():
        solve()

def read():
    global number, score
    number = int(input())
    if number == 0:
        return False
    score = list(map(int, input().split()))
    return True

def solve():
    score.sort()
    total_sum = sum(score[1:number-1])
    print(total_sum // (number - 2))

main()
# End of Code
