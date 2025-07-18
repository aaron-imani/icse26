import sys

data = list(map(int, sys.stdin.read().split()))
count = data[0]
numbers = data[1:1+count]
print(' '.join(map(str, reversed(numbers))))
# End of Code
