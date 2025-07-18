import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    i = 0
    while i < len(data):
        number = data[i]
        i += 1
        if number == 0:
            break
        scores = data[i:i+number]
        i += number
        scores.sort()
        total = sum(scores[1:-1])
        average = total // (number - 2)
        print(average)

if __name__ == "__main__":
    main()
# End of Code
