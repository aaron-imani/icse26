def main():
    import sys
    input = sys.stdin.read
    data = list(map(int, input().split()))
    N = data[0]
    max_val = min_val = data[1]
    for i in range(1, N):
        in_val = data[i + 1]
        max_val = max(max_val, in_val)
        min_val = min(min_val, in_val)
    print(max_val - min_val)

if __name__ == "__main__":
    main()
# End of Code
