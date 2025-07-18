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
    for i in range(10**n):
        s = f'{{i:0{n}d}}'
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
                if j == 0 and digit == 0 and n != 1:
                    valid = False
                    break
        if valid:
            print(s)
            return
    print(-1)
if __name__ == "__main__":
    main()
# End of Code
