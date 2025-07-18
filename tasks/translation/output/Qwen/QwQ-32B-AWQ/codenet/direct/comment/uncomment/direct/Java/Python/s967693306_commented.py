import sys

def main():
    n, m = map(int, sys.stdin.readline().split())
    constraints = {}
    for _ in range(m):
        s, c = map(int, sys.stdin.readline().split())
        if s in constraints:
            if constraints[s] != c:
                print(-1)
                return
        constraints[s] = c
    for i in range(1000):
        s = str(i)
        if len(s) != n:
            continue
        valid = True
        for j in range(n):
            pos = j + 1
            req_c = constraints.get(pos)
            digit = int(s[j])
            if req_c is not None:
                if digit != req_c:
                    valid = False
                    break
            else:
                if digit != 0:
                    if j == 0 and digit == 1:
                        pass
                    else:
                        valid = False
                        break
        if valid:
            print(s)
            return
    print(-1)

if __name__ == "__main__":
    main()
# End of Code
