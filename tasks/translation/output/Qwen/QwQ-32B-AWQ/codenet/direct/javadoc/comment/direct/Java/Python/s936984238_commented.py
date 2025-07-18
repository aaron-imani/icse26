import sys

def main():
    data = list(map(int, sys.stdin.read().split()))
    iter_data = iter(data)
    while True:
        n = next(iter_data)
        if n == 0:
            break
        scores = [next(iter_data) for _ in range(n)]
        scores.sort()
        total = sum(scores[1:-1])
        print(total // (n - 2))

if __name__ == "__main__":
    main()
# End of Code
