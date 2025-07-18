def main():
    import sys

    input = sys.stdin.read().splitlines()
    N, M = map(int, input[0].split())

    shortage = []

    for i in range(1, M + 1):
        A = int(input[i])
        shortage.append(N - A if N > A else 0)

    shortage.sort()

    ans = sum(shortage[:-1])

    print(ans)

if __name__ == "__main__":
    main()
# End of Code
