def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    cnt = 0
    while all(x % 2 == 0 for x in arr):
        arr = [x // 2 for x in arr]
        cnt += 1
    print(cnt)

if __name__ == "__main__":
    main()
# End of Code
