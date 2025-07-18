import sys
data = list(map(int, sys.stdin.read().split()))
count = data[0]
givingNumbers = data[1:1 + count]
print(' '.join(map(str, givingNumbers[::-1])))
# End of Code
