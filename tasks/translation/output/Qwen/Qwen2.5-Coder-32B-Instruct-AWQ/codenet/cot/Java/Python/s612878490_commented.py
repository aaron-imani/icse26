import sys

def main():
    input = sys.stdin.read().splitlines()
    line = input[0]
    N, M = map(int, line.split())

    shortage = []

    for i in range(1, M + 1):
        line = input[i]
        A = int(line.split()[0])
        shortage.append(N - A if N > A else 0)

    shortage.sort()

    ans = sum(shortage[:-1])

    print(ans)

if __name__ == "__main__":
    main()
# End of Code
