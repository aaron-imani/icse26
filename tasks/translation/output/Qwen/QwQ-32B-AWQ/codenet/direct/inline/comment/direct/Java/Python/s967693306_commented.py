def solve():
    n = int(input())
    m = int(input())
    required = {}
    for _ in range(m):
        s, c = map(int, input().split())
        if s in required:
            if required[s] != c:
                print(-1)
                exit()
        required[s] = c
    for num in range(1000):
        s = str(num)
        if len(s) != n:
            continue
        valid = True
        for j in range(n):
            pos = j + 1
            digit = int(s[j])
            if pos in required:
                if digit != required[pos]:
                    valid = False
                    break
            else:
                if digit != 0:
                    if not (j == 0 and digit == 1):
                        valid = False
                        break
        if valid:
            print(s)
            exit()
    print(-1)

solve()  # End of Code
