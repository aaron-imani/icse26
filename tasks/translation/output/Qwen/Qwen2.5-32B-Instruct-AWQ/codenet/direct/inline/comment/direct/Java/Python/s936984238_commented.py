import sys

def main():
    while True:
        number = int(input())
        if number == 0:
            break
        
        scores = list(map(int, input().split()))
        
        solve(scores, number)

def solve(scores, number):
    scores.sort()
    total_sum = sum(scores[1:number-1])
    print(total_sum // (number - 2))

if __name__ == "__main__":
    main()  # End of Code
