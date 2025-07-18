def main():
    import sys
    input = sys.stdin.read().split()
    N = int(input[0])
    arr = list(map(int, input[1:N+1]))
    max_val = 0
    count = 0
    for num in arr:
        if num >= max_val:
            count += 1
            max_val = num
    print(count)

if __name__ == "__main__":
    main()
# End of Code
