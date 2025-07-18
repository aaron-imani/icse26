import sys

def solve():
    input = sys.stdin.read
    data = input().split()
    
    N = int(data[0])
    max_val = min_val = int(data[1])
    
    for i in range(2, N + 1):
        num = int(data[i])
        max_val = max(max_val, num)
        min_val = min(min_val, num)
        
    print(max_val - min_val)

solve()  # End of Code
