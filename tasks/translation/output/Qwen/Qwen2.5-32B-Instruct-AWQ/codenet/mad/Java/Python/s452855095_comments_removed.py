n = int(input())
arr = list(map(int, input().split()))
cnt = 0

while all(x % 2 == 0 for x in arr):
    arr = [x // 2 for x in arr]
    cnt += 1

print(cnt)  # End of Code
