def main():
    import sys
    def next_int():
        return int(sys.stdin.readline())
    def next_array():
        return list(map(int, sys.stdin.readline().split()))
    N = next_int()
    arr = next_array()
    max_val = 0
    output = 0
    for num in arr:
        if max_val <= num:
            max_val = num
            output += 1
    print(output)

if __name__ == "__main__":
    main()
# End of Code
