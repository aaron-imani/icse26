import sys

def main():
    line = sys.stdin.readline().strip()
    N, M = map(int, line.split())
    shortage = []
    for _ in range(M):
        A = int(sys.stdin.readline().strip())
        shortage.append(max(0, N - A))
    shortage.sort()
    print(sum(shortage[:-1]))

if __name__ == "__main__":
    main()
# End of Code
