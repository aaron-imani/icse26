def main():
    N = int(input())
    arr = list(map(int, input().split()))
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
