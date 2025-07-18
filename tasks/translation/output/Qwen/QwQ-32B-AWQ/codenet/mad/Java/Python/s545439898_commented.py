count = int(input())
numbers = list(map(int, input().split()))
for i in range(count-1, -1, -1):
    print(numbers[i], end='')
    if i > 0:
        print(' ', end+)
print()
# End of Code
