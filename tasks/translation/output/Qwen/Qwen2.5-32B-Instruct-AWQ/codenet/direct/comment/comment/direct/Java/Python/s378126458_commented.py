import sys

def main():
    input = sys.stdin.read
    data = input().split()
    
    idx = 0
    N = int(data[idx])
    Q = int(data[idx+1])
    idx += 2
    
    s = data[idx]
    idx += 1
    
    pre = [0] * (N + 1)
    for i in range(1, N):
        if s[i-1] == 'A' and s[i] == 'C':
            pre[i] = 1  # initially the prefix sum array is the k array
    
    # Building the psa
    for i in range(1, N):
        pre[i] += pre[i-1]
    
    # Querying
    for _ in range(Q):
        l = int(data[idx]) - 1
        r = int(data[idx+1]) - 1
        idx += 2
        print(pre[r] - pre[l])

if __name__ == "__main__":
    main()  # End of Code
