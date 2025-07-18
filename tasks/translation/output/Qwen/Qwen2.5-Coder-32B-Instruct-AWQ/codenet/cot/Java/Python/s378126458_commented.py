import sys

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    Q = int(data[1])
    s = data[2]
    pre = [0] * (N + 1)
    
    for i in range(1, N):
        if s[i - 1] == 'A' and s[i] == 'C':
            pre[i] = 1
    
    for i in range(1, N):
        pre[i] += pre[i - 1]
    
    index = 3
    for _ in range(Q):
        l = int(data[index]) - 1
        r = int(data[index + 1]) - 1
        index += 2
        print(pre[r] - pre[l])

if __name__ == "__main__":
    main()
# End of Code
