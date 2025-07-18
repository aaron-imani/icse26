import sys

def main():
    K, S = map(int, sys.stdin.readline().split())
    ans = 0
    for x in range(K + 1):
        for y in range(K + 1):
            z = S - x - y
            if 0 <= z <= K:
                ans += 1
    print(ans)

if __name__ == "__main__":
    main()
# End of Code
