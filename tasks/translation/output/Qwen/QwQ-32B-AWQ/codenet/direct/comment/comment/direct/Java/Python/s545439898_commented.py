import sys

tokens = list(map(int, sys.stdin.read().split()))
count = tokens[0]
numbers = tokens[1:1+count]

print(' '.join(map(str, numbers[::-1])))
# End of Code
