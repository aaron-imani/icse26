import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    i = 0
    while True:
        n = data[i]
        i += 1
        if n == 0:
            break
        scores = data[i:i+n]
        i += n
        scores.sort()
        total = sum(scores[1:-1])
        print(total // (n - 2))

if __name__ == "__main__":
    main()
# End of Code
