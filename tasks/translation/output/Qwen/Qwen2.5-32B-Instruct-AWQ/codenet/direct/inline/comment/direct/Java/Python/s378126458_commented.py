import sys

def main():
    input = sys.stdin.read
    data = input().split()
    index = 0
    
    N = int(data[index])
    index += 1
    Q = int(data[index])
    index += 1
    s = data[index]
    index += 1
    
    pre = [0] * (N + 1)
    
    for i in range(1, N):
        if s[i-1] == 'A' and s[i] == 'C':
            pre[i] = 1
    
    for i in range(1, N):
        pre[i] += pre[i-1]
    
    for _ in range(Q):
        l = int(data[index]) - 1
        index += 1
        r = int(data[index])
        index += 1
        print(pre[r-1] - pre[l])

if __name__ == "__main__":
    main()  # End of Code
