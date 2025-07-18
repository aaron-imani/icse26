import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    idx = 0
    while True:
        n = data[idx]
        idx += 1
        if n == 0:
            break
        scores = data[idx:idx+n]
        idx += n
        scores.sort()
        s = sum(scores[1:-1])
        print(s // (n-2))

if __name__ == "__main__":
    main()
# End of Code
