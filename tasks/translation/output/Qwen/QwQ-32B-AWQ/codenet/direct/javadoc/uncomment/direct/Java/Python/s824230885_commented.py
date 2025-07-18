N = int(input())
arr = list(map(int, input().split()))
max_so_far = 0
output = 0
for num in arr:
    if num >= max_so_far:
        output +=1
        max_so_far = num
print(output)
# End of Code
