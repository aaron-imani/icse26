MOD = 10**9 + 7

def main():
    import sys
    data = sys.stdin.read().split()
    n = int(data[0])
    a = list(map(int, data[1:n+1]))
    ans = 0
    s = a[-1]
    for i in range(n-2, -1, -1):
        ans = (ans + (s * a[i]) % MOD) % MOD
        s = (s + a[i]) % MOD
    print(ans % MOD)

if __name__ == "__main__":
    main()
# End of Code
