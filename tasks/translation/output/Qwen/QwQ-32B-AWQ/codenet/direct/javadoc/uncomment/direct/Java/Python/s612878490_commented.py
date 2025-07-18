import sys

def main():
    N, M = map(int, sys.stdin.readline().split())
    shortage = []
    for _ in range(M):
        A = int(sys.stdin.readline())
        shortage.append(max(0, N - A))
    shortage.sort()
    print(sum(shortage[:-1]))

if __name__ == "__main__":
    main()
# End of Code
