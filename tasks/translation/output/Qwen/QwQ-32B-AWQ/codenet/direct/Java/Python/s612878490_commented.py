def main():
    first_line = input().split()
    N = int(first_line[0])
    M = int(first_line[1])
    shortage = []
    for _ in range(M):
        A = int(input())
        shortage.append(max(0, N - A))
    shortage.sort()
    print(sum(shortage[:-1]))

if __name__ == "__main__":
    main()
# End of Code
