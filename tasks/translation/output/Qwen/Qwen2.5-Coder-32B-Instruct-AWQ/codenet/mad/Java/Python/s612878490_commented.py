import sys

def main():
    line = sys.stdin.readline().strip()
    N, M = map(int, line.split())

    shortage = []

    for _ in range(M):
        A = int(sys.stdin.readline().strip().split()[0])
        shortage.append(N - A if N > A else 0)

    shortage.sort()

    ans = sum(shortage[:-1])

    print(ans)

if __name__ == "__main__":
    main()
# End of Code
