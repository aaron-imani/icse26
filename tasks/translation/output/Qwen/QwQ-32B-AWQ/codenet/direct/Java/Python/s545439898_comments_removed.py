import sys

data = list(map(int, sys.stdin.read().split()))
count = data[0]
nums = data[1:count+1]
print(' '.join(map(str, reversed(nums))))
# End of Code
