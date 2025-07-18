def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))
    N = data[0]
    max_val = min_val = data[1]
    for i in range(2, N + 1):
        val = data[i]
        max_val = max(max_val, val)
        min_val = min(min_val, val)
    print(max_val - min_val)

if __name__ == "__main__":
    main()
# End of Code
