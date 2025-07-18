import sys

def main():
    while True:
        try:
            number = int(input().strip())
            if number == 0:
                break
            scores = list(map(int, input().strip().split()))
            solve(scores, number)
        except EOFError:
            break

def solve(scores, number):
    scores.sort()
    total = sum(scores[1:number-1])
    print(total // (number - 2))

if __name__ == "__main__":
    main()
# End of Code
