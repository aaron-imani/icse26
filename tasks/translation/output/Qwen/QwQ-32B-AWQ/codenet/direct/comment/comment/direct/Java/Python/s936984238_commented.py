import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    while idx < len(data):
        number = data[idx]
        idx += 1
        if number == 0:
            break
        scores = data[idx:idx+number]
        idx += number
        scores.sort()
        s = sum(scores[1:-1])
        print(s // (number - 2))

if __name__ == "__main__":
    main()
# End of Code
