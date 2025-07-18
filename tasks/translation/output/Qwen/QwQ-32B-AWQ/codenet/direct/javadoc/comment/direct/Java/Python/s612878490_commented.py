import sys

def main():
    # Read first line
    first_line = sys.stdin.readline().strip()
    parts = first_line.split()
    N = int(parts[0])
    M = int(parts[1])

    shortage = []
    for _ in range(M):
        a = int(sys.stdin.readline().strip())
        shortage.append(N - a if N > a else 0)
    
    shortage.sort()
    ans = sum(shortage[:-1])
    print(ans)

if __name__ == "__main__":
    main()

# End of Code
