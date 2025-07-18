import sys

def main():
    parts = sys.stdin.readline().split()
    n = int(parts[0])
    m = int(parts[1])
    conditions = {}
    conflict = False
    for _ in range(m):
        parts = sys.stdin.readline().split()
        s = int(parts[0])
        c = int(parts[1])
        if s in conditions:
            if conditions[s] != c:
                print(-1)
                return
        conditions[s] = c
    for i in range(1000):
        s = str(i)
        if len(s) < n:
            continue
        flag = True
        for j in range(n):
            current_digit = int(s[j])
            pos = j + 1
            if pos in conditions:
                if current_digit != conditions[pos]:
                    flag = False
                    break
            else:
                if current_digit != 0:
                    if not (j == 0 and current_digit == 1):
                        flag = False
                        break
        if flag and len(s) == n:
            print(s)
            return
    print(-1)

if __name__ == "__main__":
    main()
# End of Code
