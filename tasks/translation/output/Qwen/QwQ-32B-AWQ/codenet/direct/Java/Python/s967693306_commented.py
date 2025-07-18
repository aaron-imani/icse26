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
            digit = int(s[j])
            required = constraints.get(pos)
            if required is not None:
                if digit != required:
                    valid = False
                    break
            else:
                if digit != 0:
                    if j != 0 or digit != 1:
                        valid = False
                        break
        if valid:
            print(s)
            return
    print(-1)

if __name__ == "__main__":
    main()
# End of Code
