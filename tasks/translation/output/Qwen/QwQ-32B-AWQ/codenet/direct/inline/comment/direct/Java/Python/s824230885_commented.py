def main():
    N = int(input())
    arr = list(map(int, input().split()))
    max_val = 0
    count = 0
    for num in arr:
        if num >= max_val:
            max_val = num
            count +=1
    print(count)

if __name__ == "__main__":
    main()
# End of Code
