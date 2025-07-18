import sys

def main():
    line = input().strip()
    N, M = map(int, line.split())

    shortage = []
    for i in range(M):
        line = input().strip()
        A = int(line.split()[0])
        shortage.append(max(N - A, 0))

    shortage.sort()

    ans = sum(shortage[:-1])

    print(ans)

if __name__ == "__main__":
    main()  # End of Code
