def main():
    N = int(input())
    in_values = list(map(int, input().split()))
    max_val = min_val = in_values[0]
    for i in range(1, N):
        max_val = max(max_val, in_values[i])
        min_val = min(min_val, in_values[i])
    print(max_val - min_val)

if __name__ == "__main__":
    main()
# End of Code
