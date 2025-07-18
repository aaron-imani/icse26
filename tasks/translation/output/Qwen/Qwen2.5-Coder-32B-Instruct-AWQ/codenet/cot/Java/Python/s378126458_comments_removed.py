import sys

def main():
    input = sys.stdin.read().split()
    N = int(input[0])
    Q = int(input[1])
    s = input[2]
    pre = [0] * (N + 1)
    
    for i in range(1, N):
        if s[i - 1] == 'A' and s[i] == 'C':
            pre[i] = 1

    for i in range(1, N):
        pre[i] += pre[i - 1]

    idx = 3
    while Q > 0:
        l = int(input[idx]) - 1
        r = int(input[idx + 1]) - 1
        print(pre[r] - pre[l])
        idx += 2
        Q -= 1

if __name__ == "__main__":
    main()
# End of Code
